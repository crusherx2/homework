#include "binSearch.h"

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

int binSearch(int n[], int e, int length) {
	if (e > n[length - 1]) return length;
	return binSearch(n, e, 0, length);
}
int binSearch(int n[], int e, int lo, int hi) {
	while (1 < hi - lo) {
		int mi = lo + ((hi - lo) >> 1);
		if (e < n[mi]) hi = mi;
		else lo = mi;
	}
	return n[lo];
}