#include "Node.h"

namespace LIST{

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

enum ListType {
	SINGLY, 
	DUAL,
};

template <typename T> 
class List {
private:
	int _size;
	ListType _mode;
	NodePos(T) _head;
	NodePos(T) _tail;

protected:
	initSingly();
	initDual();

	clear();
	
public:
	List() { List(DUAL); };
	List(ListType Type);
	NodePos(T) insertBefore(NodePos(T) p, T e);
	NodePos(T) insertAfter(NodePos(T) p, T e);
	T remove(NodePos(T) p);
	NodePos(T) operator [] (Rank r);
	int size() { return _size; };
	~List();
};

template <typename T> 
List<T>::List(ListType Type){
	switch (Type){
		case SINGLY:
			initSingly();
			break;
		case DUAL:
			initDual():
			break;
		default:
			break;
	}
}

template <typename T> 
void List<T>::initSingly(){
	_size = 0;
	_mode = SINGLY;
	_head = new Node(NULL, NULL);
}

template <typename T> 
void List<T>::initDual(){
	_size = 0;
	_mode = DUAL;
	_head = new Node(NULL, NULL);
	_tail = new Node(NULL, NULL);
	_head->succ = _tail;
	_tail->pred = _head;
}

template <typename T> 
NodePos(T) List<T>::insertBefore(NodePos(T) p, T e){
	Node newNode = new Node(e, p->pred, p);
	p->pred->succ = newNode;
	p->pred = newNode;
	_size ++;
}

template <typename T> 
NodePos(T) List<T>::insertAfter(NodePos(T) p, T e){
	Node newNode = new Node(e, p, p->succ);
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
NodePos(T) operator [] (Rank r){
	if (r >= 0){
		NodePos(T) p = _head;
		while (0 < r--)  p = p->succ;
	}else{
		NodePos(T) p = _tail->pred;
		while (0 < r--)  p = p->pred;
	}
	return p;
}

}
