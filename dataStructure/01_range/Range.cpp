#include <cstdio>

void mergeSort(int n[], int length);
void mergeSort(int n[], int lo, int hi);
void merge(int n[], int lo, int mi, int hi);
int binSearchBackward(int n[], int e, int length);
int binSearchBackward(int n[], int e, int lo, int hi);

int main()
{
#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	int lenNum, lenRange = 0;
	scanf("%d %d\n", &lenNum, &lenRange);
	int *numArr = new int[lenNum];
	int(*rangeArr)[2] = new int[lenRange][2];
	for (int i = 0; i < lenNum; i++) {
		scanf("%d", &numArr[i]);
	}
	for (int i = 0; i < lenRange; i++) {
		scanf("%d", &rangeArr[i][0]);
		scanf("%d", &rangeArr[i][1]);
	}
	mergeSort(numArr, lenNum);
	for (int i = 0; i < lenRange; i++) {
		int lo = binSearchBackward(numArr, rangeArr[i][0], lenNum);
		int hi = binSearchBackward(numArr, rangeArr[i][1] + 1, lenNum);
		printf("%d", hi - lo); if (i != lenRange - 1) printf("\n");
	}
	delete[] numArr;
	delete[] rangeArr;
    return 0;
}

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
	for (int i=0, j=0, k=0; (j < lb) || (k < lc);) {
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] <  B[j]))) A[i++] = C[k++];
	}
	delete[] B;
}

int binSearchBackward(int n[], int e, int length) {
	if (e > n[length - 1]) return length;
	return binSearchBackward(n, e, 0, length);
}
int binSearchBackward(int n[], int e, int lo, int hi) {
	while (1 < hi - lo) {
		int mi = lo + ((hi - lo) >> 1);
		if (e < n[mi]) hi = mi;
		else if (n[mi] < e) lo = mi;
		else {
			if (e == n[mi - 1]) hi = mi;
			else lo = mi;
		}
	}
	return n[lo] < e ? hi : lo;
}
