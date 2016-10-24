typedef struct{
	int lo;
	int hi;
	int sum;
}MaxSumSubarray;

MaxSumSubarray findMaxSumCrossSubarray(int lo, int mi, int hi, int A[]);

MaxSumSubarray findMaxSumSubarray(int lo, int hi, int A[]);
