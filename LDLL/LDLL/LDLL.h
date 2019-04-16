#include <iostream>
using namespace std;
#include "DNode.h"
#ifndef LDLL_H
#define LDLL_H
template <typename T>
class LDLL
{
	DNode<T> * head;
public:
	LDLL();
	LDLL(const LDLL &);
	~LDLL();
	LDLL & operator=(const LDLL &);
	void insertAtHead(T);
	void insertAtTail(T);
	void insertAfter(T, T);
	void insertBefore(T, T);
	void remove(T);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T);
	void removeBefore(T);
};
#endif