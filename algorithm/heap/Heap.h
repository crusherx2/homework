template <typename T>
class Heap{
private:
	int _size;
	int _parent(i) {return i>>1;};
	int _leftChild(i) {return i<<2;};
	int _rightChild(i) {return (i<<2) + 1;};
	void swap(T x, T y);

protected:
	void maxHeapify(T Arr[], int len, int i);
	void minHeapify(T Arr[], int len, int i){};
public:
	//TODO: construction, destruction, self-expand, self-shrink, insert, 
	Heap();
	~Heap();
	void sort();
	void insert(T e);
	T maximum() { return A[1]; };
	T extractMax();
	void increaseKey(int k, int newk);
	void remove(int i){};
};


template <typename T>
Heap<T>::Heap(){

}

template <typename T>
Heap<T>::Heap(T Arr[], int len){
	_size = len;
	for (int i = 0; i < len; i++){
		maxHeapify(Arr, i);
	}
}

template <typename T>
Heap<T>::~Heap(){

}

template <typename T>
void Heap<T>::maxHeapify(T Arr[], int len, int i){
	int left = _leftChild(i);
	int right = _rightChild(i);
	int max = 0;
	if (l <= len && Arr[l] > Arr[i])  max = l;
	else  max = i;
	if (r <= len && Arr[r] > Arr[i])  max = r;
	if (max != i){
		T tmp = Arr[i];
		Arr[i] = Arr[max];
		Arr[max] = tmp;
		maxHeapify(T, max);
	}
}

template <typename T>
void Heap<T>::sort(){
	for (int i=_size; i<=2; i--){
		T tmp = Arr[i];
		Arr[i] = Arr[max];
		Arr[max] = tmp;
		_size --;
		maxHeapify(Arr, _size, 1);
	}
}

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
