#include "mergeSort.h"

void mergeSort(int n[], int length) {
	mergeSort(n, 0, length);
}
void mergeSort(int n[], int lo, int hi) {
	if (hi - lo < 2) return;
	int mi = lo + ((hi - lo) >> 1);
	mergeSort(n, lo, mi);
	mergeSort(n, mi, hi);
	merge(n, lo, mi, hi);
}

void merge(int n[], int lo, int mi, int hi) {
	int *A = n + lo;
	int lb = mi - lo; int *B = new int[lb]; for (int i = 0; i < lb; B[i] = A[i++]);
	int lc = hi - mi; int *C = n + mi;
	for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] <  B[j]))) A[i++] = C[k++];
	}
	delete[] B;
}