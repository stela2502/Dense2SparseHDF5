// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/Dense2SparseHDF5.h"
#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

// Matr
Eigen::SparseMatrix<double> Matr(int nrow, int ncol, int size);
RcppExport SEXP _Dense2SparseHDF5_Matr(SEXP nrowSEXP, SEXP ncolSEXP, SEXP sizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nrow(nrowSEXP);
    Rcpp::traits::input_parameter< int >::type ncol(ncolSEXP);
    Rcpp::traits::input_parameter< int >::type size(sizeSEXP);
    rcpp_result_gen = Rcpp::wrap(Matr(nrow, ncol, size));
    return rcpp_result_gen;
END_RCPP
}
// NotNull
int NotNull(NumericMatrix X);
RcppExport SEXP _Dense2SparseHDF5_NotNull(SEXP XSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type X(XSEXP);
    rcpp_result_gen = Rcpp::wrap(NotNull(X));
    return rcpp_result_gen;
END_RCPP
}
// add
Eigen::SparseMatrix<double> add(Eigen::SparseMatrix<double> X, NumericMatrix dat, int offset, int alloc, bool progressBar);
RcppExport SEXP _Dense2SparseHDF5_add(SEXP XSEXP, SEXP datSEXP, SEXP offsetSEXP, SEXP allocSEXP, SEXP progressBarSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::SparseMatrix<double> >::type X(XSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type dat(datSEXP);
    Rcpp::traits::input_parameter< int >::type offset(offsetSEXP);
    Rcpp::traits::input_parameter< int >::type alloc(allocSEXP);
    Rcpp::traits::input_parameter< bool >::type progressBar(progressBarSEXP);
    rcpp_result_gen = Rcpp::wrap(add(X, dat, offset, alloc, progressBar));
    return rcpp_result_gen;
END_RCPP
}
// addVector
NumericMatrix addVector(NumericMatrix dat, int offset, int alloc, bool progressBar);
RcppExport SEXP _Dense2SparseHDF5_addVector(SEXP datSEXP, SEXP offsetSEXP, SEXP allocSEXP, SEXP progressBarSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type dat(datSEXP);
    Rcpp::traits::input_parameter< int >::type offset(offsetSEXP);
    Rcpp::traits::input_parameter< int >::type alloc(allocSEXP);
    Rcpp::traits::input_parameter< bool >::type progressBar(progressBarSEXP);
    rcpp_result_gen = Rcpp::wrap(addVector(dat, offset, alloc, progressBar));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_Dense2SparseHDF5_Matr", (DL_FUNC) &_Dense2SparseHDF5_Matr, 3},
    {"_Dense2SparseHDF5_NotNull", (DL_FUNC) &_Dense2SparseHDF5_NotNull, 1},
    {"_Dense2SparseHDF5_add", (DL_FUNC) &_Dense2SparseHDF5_add, 5},
    {"_Dense2SparseHDF5_addVector", (DL_FUNC) &_Dense2SparseHDF5_addVector, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_Dense2SparseHDF5(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
