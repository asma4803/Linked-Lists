#include <iostream>
using namespace std;
#ifndef LSLL_H
#define LSLL_H
#include "Node.h"
template <typename T>
class LSLL
{
	Node <T> * head;
public:
	/*class Iterator
	{
		LSLL<T> * list;
		Node<T>* curr;
	public:
		Iterator();
		Iterator(LSLL<T>* );
		T & operator *();
		void next();
		bool isDone();
		void setList(LSLL <T>*);
		void start();
	};*/
	LSLL();
	~LSLL();
	LSLL & operator =(const LSLL &);
	LSLL(const LSLL &);
	void insertAtHead(T);
	void insertAtTail(T);
	void insertAfter( T,T);
	void insertBefore( T,T);
	void remove(T);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T);
	void removeBefore(T);
};
#endif