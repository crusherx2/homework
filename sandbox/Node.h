#include <iostream>



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
	// NodePos(T) insertAsPred(T const& e);
	// NodePos(T) insertAsSucc(T const& e);
};

// template <typename T> 
// NodePos(T) Node<T>::insertAsPred(T const &e){
// 	//TODO strengthen robustness
// 	NodePos(T) x = new Node(e, pred, this);
// 	pred->succ = x;
// 	pred = x;
// 	return x;
// }

// template <typename T> 
// NodePos(T) Node<T>::insertAsSucc(T const &e){
// 	//TODO strengthen robustness
// 	NodePos(T) x = new Node(e, this, succ);
// 	succ->pred = x;
// 	succ = x;
// 	return x;
// }

}