#include <iostream>
using namespace std;
#ifndef CSLL_H
#define CSLL_H
#include "Node.h"
template <typename T>
class CSLL
{
	Node <T> * head;
public:
	CSLL();
	~CSLL();
	CSLL & operator=(const CSLL &);
	CSLL(const CSLL &);
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