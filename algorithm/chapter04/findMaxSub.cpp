#include "findMaxSub.h"

MaxSumSubarray findMaxSumCrossSubarray(int lo, int mi, int hi, int A[]) {
	MaxSumSubarray result = { 0 };
	int sumLeft = ((unsigned)(-1) >> 1) + 1;
	int sumRight = ((unsigned)(-1) >> 1) + 1;

	for (int i = mi-1, sum = 0; i >= lo; i--) {
		sum += A[i];
		if (sum > sumLeft) {
			sumLeft = sum;
			result.lo = i;
		}
	}
	for (int i = mi, sum = 0; i < hi; i++) {
		sum += A[i];
		if (sum > sumRight) {
			sumRight = sum;
			result.hi = i + 1;
		}
	}
	result.sum = sumLeft + sumRight;
	return result;
}

MaxSumSubarray findMaxSumSubarray(int lo, int hi, int A[]){
	MaxSumSubarray result = { 0 };
	if (hi - lo <= 1) {
		result.lo = lo;
		result.hi = hi;
		result.sum = A[lo];
		return result;
	}else{
		int mi = lo + ((hi - lo)>>1);
		MaxSumSubarray left = findMaxSumSubarray(lo, mi, A);
		MaxSumSubarray right = findMaxSumSubarray(mi, hi, A);
		MaxSumSubarray cross = findMaxSumCrossSubarray(lo, mi, hi, A);
		if (left.sum > right.sum && left.sum > cross.sum)  return left;
		else if (right.sum > left.sum && right.sum > cross.sum)  return right;
		else  return cross;
	}
}
