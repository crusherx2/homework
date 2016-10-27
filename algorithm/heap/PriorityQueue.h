template <typename T>
class PriorityQueue : public Heap{
public:
	PriorityQueue();
	~PriorityQueue();
	void insert(T e);
	T maximum() { return A[1]; };
	T extractMax();
	void increaseKey(int k, int newk);
};

template <typename T>
T extractMax(){
	if (_size < 1)
		return 0;
	max = A[1];
	A[1] = A[_size];
	_size --;
	maxHeapify(Arr[], len, i);
	return max;
}

template <typename T>
void PriorityQueue<T>::increaseKey(int i, int k){
	if (k < A[i])
		return 0;
	A[i] = k;
	while (i > 1 && A[_parent(i)] < S[i]){
		swap(A[i], A[_parent(i)]);
		i = _parent(i);
	}
}

template <typename T>
void insert(T e){
	_size ++;
	A[_size] = -10000;
	increaseKey(k);
}
