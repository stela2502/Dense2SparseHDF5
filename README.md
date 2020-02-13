# Dense2SparseHDF5

This R package is meant to easily convert a HDF5 dense matrix, which is found in several .loom files 
and can easily be too big for a normal analysis desktop (64Gb RAM), into a R sparse matrix.

The process in implemented in c++ using the Rcpp package, but needs further speed improvements.

# Install

```
install.packagaes('devtools')

devtools::install_git('https://github.com/stela2502/Dense2SparseHDF5.git')

```

# Usage

```
library(Dense2SparseHDF5)

file ="someFile.loom"

obj= Dense2SparseHDF5$new(file)

obj$toSparseVector( slot='matrix', block_size=1000 )

obj$Matrix

```

If the default approach fails try to change the block_size from the default 1e+3 to some other value (e.g. 1e+4).

