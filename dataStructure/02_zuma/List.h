#include "ListNode.h"

template <typename T> 
class List {
private:
	int _size; ListNodePos(T) _header; ListNodePos(T) _trailer;

protected:
	void init();
	int clear();

public:
	List() { init(); };
	~List() { clear();  delete _header;  delete _trailer; };
	ListNodePos(T) getByRank(Rank r) const;
	Rank size() { return _size; };
	bool isEmpty() { return _size <= 0; };
	bool isValid(ListNodePos(T) p) { return p && (_trailer != p) && (_header != p); };
	ListNodePos(T) insertAsFirst(T const& e) { _size++; return _header->insertAsSucc(e); };
	ListNodePos(T) insertAsLast(T const& e) { _size++; return _trailer->insertAsPred(e); };
	ListNodePos(T) insertAfter(ListNodePos(T) p, T const& e) { _size++; return p->insertAsSucc(e); };
	ListNodePos(T) insertBefore(ListNodePos(T) p, T const& e) { _size++; return p->insertAsPred(e); };
	ListNodePos(T) insertByRank(Rank r, T const& e) { return insertBefore(getByRank(r), e); };
	T remove(ListNodePos(T) p);
	int scanPred(ListNodePos(T) p, T const& e); //从p前一节点开始向前扫描, 元素与p相同的个数
	int scanSucc(ListNodePos(T) p, T const& e); //从p节点开始向后扫描, 元素与p相同的个数
	ListNodePos(T) first() const { return _header->succ; };
	void display() const;
	void zumaClear(ListNodePos(T) p);
};

template <typename T>
void List<T>::init() {
	_header = new ListNode<T>;
	_trailer = new ListNode<T>;
	_header->succ = _trailer;  _header->pred = NULL;
	_trailer->pred = _header;  _trailer->succ = NULL;
	_size = 0;
};

template <typename T>
ListNodePos(T) List<T>::getByRank(Rank r) const {
	ListNodePos(T) p = first();
	while (0 < r--)  p = p->succ;
	return p;
};

template <typename T>
T List<T>::remove(ListNodePos(T) p) {
	T e = p->data;
	p->pred->succ = p->succ;  p->succ->pred = p->pred;
	delete p;  _size--;
	return e;
};

template <typename T>
int List<T>::clear() {
	int oldSize = _size;
	while (0 < _size)  remove(_header->succ);
	return oldSize;
};

template <typename T>
int List<T>::scanPred(ListNodePos(T) p, T const& e) {
	int i;
	for (i = 0; p->pred->data == e; i++)  p = p->pred;
	return i;
};

template <typename T>
int List<T>::scanSucc(ListNodePos(T) p, T const& e) {
	int i;
	for (i = 0; p->data == e; i++)  p = p->succ;
	return i;
};

template <typename T>
void List<T>::display() const {
	if (_size == 0) {
		printf("-\n");
		return;
	}
	ListNodePos(T) p = _header;
	int size = _size;
	while (0 < size--) {
		p = p->succ;
		printf("%c", p->data);
	}
	printf("\n");
};

template <typename T>
void List<T>::zumaClear(ListNodePos(T) p) {
	int predNum = scanPred(p, p->data);
	int succNum = scanSucc(p, p->data);
	ListNodePos(T) h = p;
	while (predNum + succNum > 2) {
		for (int i = 0; i < predNum + 1; i++)  h = h->pred;
		for (int i = 0; i < predNum + succNum; i++)  remove(h->succ);
		if (h == _header)  return;
		predNum = scanPred(h, h->data);
		succNum = scanSucc(h, h->data);
	}
};
