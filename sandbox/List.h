// #include "Node.h"

// namespace LIST{
/////////////////////////
typedef int Rank;
#define NodePos(T) Node<T>*

template <typename T> 
struct Node{
	T data;
	NodePos(T) pred;
	NodePos(T) succ;
	Node() {};
	Node(T e, NodePos(T) p=NULL, NodePos(T) s=NULL) : data(e), 	pred(p), succ(s) {};
	Node(T e, NodePos(T) p=NULL) : data(e),	pred(p), succ(NULL) {};
};

enum ListType{
	SINGLY, 
	DUAL,
};

template <typename T>
class List{
private:
	int _size;
	ListType _mode;
	NodePos(T) _head;
	NodePos(T) _tail;

protected:
	void initSingly();
	void initDual();
	void clear();
	
public:
	List() { List(DUAL); };
	List(ListType Type);
	NodePos(T) insertBefore(NodePos(T) p, T e);
	NodePos(T) insertAfter(NodePos(T) p, T e);
	T remove(NodePos(T) p);
	NodePos(T) operator [] (Rank r);
	int size() { return _size; };
	~List() { clear(); };
};

template <typename T>
List<T>::List(ListType Type){
	switch (Type){
		case SINGLY:
			initSingly();
			break;
		case DUAL:
			initDual();
			break;
		default:
			break;
	}
}

template <typename T>
void List<T>::initSingly(){
	_size = 0;
	_mode = SINGLY;
	_head = new Node<T>(NULL, NULL);
}

template <typename T>
void List<T>::initDual(){
	_size = 0;
	_mode = DUAL;
	_head = new Node<T>(NULL, NULL);
	_tail = new Node<T>(NULL, NULL);
	_head->succ = _tail;
	_tail->pred = _head;
}

template <typename T>
NodePos(T) List<T>::insertBefore(NodePos(T) p, T e){
	Node<T> newNode = new Node<T>(e, p->pred, p);
	p->pred->succ = newNode;
	p->pred = newNode;
	_size ++;
}

template <typename T>
NodePos(T) List<T>::insertAfter(NodePos(T) p, T e){
	Node<T> newNode = new Node<T>(e, p, p->succ);
	p->succ = newNode;
	p->succ->pred = newNode;
	_size ++;
}

template <typename T>
T List<T>::remove(NodePos(T) p){
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	_size --;
	delete p;
}

template <typename T>
NodePos(T) List<T>::operator [] (Rank r){
	NodePos(T) p;
	if (r >= 0){
		p = _head;
		while (0 < r--)  p = p->succ;
	}else{
		p = _tail;
		while (0 < r--)  p = p->pred;
	}
	return p;
}

template <typename T>
void List<T>::clear(){
	for (int i = 0; i < _size; i++)
		remove(_head->succ);
	delete _tail;
	delete _head;
}

// }
