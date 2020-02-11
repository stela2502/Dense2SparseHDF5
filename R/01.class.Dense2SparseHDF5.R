require('R6')

#' Class a simple interface to store a sparse Matrix and fill it with a HUGE dense one
#' from an HDF5 file connection.
#'
#' The main intension here is to keep memory footprint as low as possible 
#' while also trying to be as fast as possible.
#'
#' @docType class
#' @importFrom R6 R6Class
#' @field Matrix the sparse matrix
#' @field file the HDF5 connection
#' @export
Dense2SparseHDF5 <- #withFormalClass(
	R6::R6Class(
		'Dense2SparseHDF5',
		class = TRUE,
		public = list ( 
			Matrix=NULL,
			file=NULL,
			#' @description
			#' print a summary of the object
			print = function () {
				cat("containing a sparse matrix of size")
				if( ! is.null(self$Matrix) ){
					cat( paste( nrow(self$Matrix),'rows and', ncol(self$Matrix), "cols"))
				}else {
					cat ("0" )
				}
			},
			#' @description
			#' initialize the object
			#' @param fname the hdf5 file
			initialize = function(fname) {
				self$file= hdf5r::h5file(fname)
			},
			#' @description
			#' convert a dense matrix entry in the hdf5 file to sparse
			#' @param slot the slot to convert (default 'matrix')
			#' @param blockSize the read block size ( default 1000)
			toSparse = function(slot='matrix', block_size=1000 ){

				ncol = self$file[[slot]]$dims[2]
				nrow = self$file[[slot]]$dims[1]
				cols_grouped <- split(1:ncol,  (1:(ncol) %/% block_size) )
				b = 10
				while (any(unlist( lapply( cols_grouped, length)) == 1) ) {
					block_size = block_size +1
					cols_grouped <- split(1:ncol,  (1:(ncol) %/% block_size) )
					b = b-1
					if ( b == 0)
						break
				}
				message("aquiring sparsity")
				notN =  unlist(lapply( cols_grouped, function(cs) { NotNull( self$file[[slot]][, cs ]) } )) #c++
				n = sum( notN) 
				message( paste(n,"data slots from", nrow,"x", ncol,"; sparsity =", n/(nrow*ncol) ) )
				self$Matrix = Matr( as.integer(nrow), as.integer(ncol), as.integer(n) );
				message(paste('Starting data fill starting with a matrix of size', pryr::object_size(self$Matrix)) )
				alloc  = 0
				for ( id in 1:length(cols_grouped)){
					alloc = alloc+ notN[id]
					message( paste( range(cols_grouped[[id]]), "and matrix size:", pryr::object_size(self$Matrix)) )
					self$Matrix = add( self$Matrix, self$file[[slot]][, cols_grouped[[id]] ], cols_grouped[[id]][1] -1, alloc )
				}
				message('finished')
			}
		)
	);


#' @useDynLib Dense2SparseHDF5


.onAttach <- function(libname, pkgname) {
	packageStartupMessage(paste("Loading Dense2SparseHDF5 version", packageVersion('Dense2SparseHDF5') ))
	where <- as.environment("package:Dense2SparseHDF5")
	clss <- list(
			c("Dense2SparseHDF5", "R6")
	)
	## Ensure clean initial state for subsequent package loads
	## while developing //
	sapply(clss, function(cls) {
				idx <- sapply(cls, isClass )
				suppressWarnings(try(sapply(cls[idx], removeClass,
										where = where), silent = TRUE))
			})
	## Set formal class equivalent //
	sapply(clss, function(cls) {
				try(setOldClass(cls, where = where), silent = TRUE)
			})
#	r6x::formalizeClasses()
}