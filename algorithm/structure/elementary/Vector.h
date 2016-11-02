
namespace VECTOR{
typedef int Rank;

template <typename T> 
class Vector{
private:
	static const int DEFAULT_CAPACITY = 8;
	static const int CAPACITY_RATIO_MIN_OFFSET = 2; //ratio=1/(2^n)
	int _size;
	int _capacity;
	char _ordered;
	T* _vec = NULL;

protected:
	void init();
	int expand();
	int shrink();
	void mergeSort();
	void quickSort();
	T binSearch();
	T find();

public:
	Vector();
	void insert(Rank r, T e);
	void append(T e);
	void remove(Rank r);
	void remove(Rank lo, Rank hi);
	~Vector();
	
};

template <typename T> 
Vector<T>::Vector(){
	_capacity = DEFAULT_CAPACITY;
	_size = 0;

}

template <typename T>
Vector<T>::Vector(T Arr[], int len){
	
}

template <typename T>
void Vector<T>::expand(){
	if (_size >= _capacity)  return;
	_capacity <<= 1;
	T* newVec = new T[_capacity];
	for (int i = 0; i < _size; i++)  
		newVec[i] = _vec[i];
	T* tmp = _vec;
	_vec = newVec;
	delete[] tmp;
}

template <typename T>
void Vector<T>::shrink(){
	if ((_size << CAPACITY_RATIO_MIN_OFFSET) < _capacity)  return;
	_capacity >>= 1;
	T* newVec = new T[_capacity];
	for (int i = 0; i < _size; ++i)
		newVec[i] = _vec[i];
	T* tmp = _vec;
	_vec = newVec;
	delete[] tmp;
}

template <typename T>
void append(T e){
	expand();
	_vec[_size] = e;
	_size ++;
}

template <typename T>
void insert(Rank r, T e){
	expand();
	for (int i = _size; i > r; i--)
		_vec[i] = _vec[i-1];
	
}

}