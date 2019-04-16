#include <iostream>
using namespace std;
#include "DNode.h"
#ifndef CDLL_H
#define CDLL_H
template <typename T>
class CDLL
{
	DNode<T> * head;
public:
	CDLL();
	CDLL(const CDLL &);
	~CDLL();
	CDLL & operator=(const CDLL &);
	void insertAtHead(T);
	void insertAtTail(T);
	void insertAfter(T, T);
	void insertBefore(T, T);
	void remove(T);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T);
	void removeBefore(T);
	void display();
};
#endif