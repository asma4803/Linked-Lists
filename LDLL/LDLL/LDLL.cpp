#include <iostream>
using namespace std;
#include "LDLL.h"
template <typename T>
LDLL<T>::LDLL()
{
	head = 0;
}
template <typename T>
LDLL<T>::LDLL(const LDLL & ref)
{
	if (ref.head == 0)
	{
		head = 0;
		return;
	}
	DNode<T> * frwd = ref.head;
	DNode<T>*copy = new DNode<T>(frwd->info);
	frwd = frwd->next;
	head = copy;
	while (frwd != 0)
	{
		copy->next = new DNode<T>(frwd->info);
		copy = copy->next;
		frwd = frwd->next;
	}
}
template <typename T>
LDLL<T>::~LDLL()
{
	DNode<T>*q = head;
	head = head->next;
	while (head != 0)
	{
		delete q;
		q = head;
		head = head->next;
	}
}
template <typename T>
LDLL<T> & LDLL<T>::operator=(const LDLL & ref)
{
	if (this == &ref)
	{
		return *this;
	}
	if (ref.head == 0)
	{
		head = 0;
		return *this;
	}
	DNode<T> * frwd = ref.head;
	DNode<T>*copy = new DNode<T>(frwd->info);
	frwd = frwd->next;
	head = copy;
	while (frwd != 0)
	{
		copy->next = new DNode<T>(frwd->info);
		copy = copy->next;
		frwd = frwd->next;
	}
	return *this;
}
template <typename T>
void LDLL<T>::insertAtHead(T val)
{
	if (head == 0)
	{
		head = new DNode <T>(val);
		return;
	}
	else
	{
		DNode<T>*p = new DNode<T>(val);
		p->next = head;
		head->prev = p;
		head = p;
	}
}
template <typename T>
void LDLL<T>::insertAtTail(T val)
{
	if (head == 0)
	{
		head = new DNode<T>(val);
		return;
	}
	else
	{
		DNode<T>*q = new DNode<T>(val);
		DNode<T>*temp = head;
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = q;
		q->prev = temp;
		q->next = 0;
	}
}
template <typename T>
void LDLL<T>::insertAfter(T key, T val)
{
	if (head == 0)
	{
		return;
	}
	DNode<T>*temp = head;
	DNode<T>*q = new DNode<T>(val);
	while (temp != 0 && temp->info!=key)
	{
		temp = temp->next;
	}
	if (!temp)
		return;
	if (temp->next == 0)
	{
		temp->next = q;
		q->prev = temp;
		q->next = 0;
		return;
	}
	q->next = temp->next;
	temp->next->prev = q;
	temp->next = q;
	q->prev = temp;
}
template <typename T>
void LDLL<T>::insertBefore(T key, T val)
{
	if (head == 0)
	{
		return;
	}
	DNode<T>*temp = head;
	DNode<T>* q = new DNode<T>(val);
	if (head->info == key)
	{
		q->next = temp;
		head = q;
		temp->prev = q;
		return;
	}
	DNode<T>* prevNode = 0;
	while (temp != 0 && temp->info!= key)
	{
		prevNode= temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	q->next = temp;
	temp->prev = q;
	prevNode->next = q;
	q->prev = prevNode;
}
template <typename T>
void LDLL<T>::remove(T val)
{
	if (head == 0)
		return;
	if (head->info == val)
	{
		DNode<T>* temp = head;
		head = temp->next;
		temp->next->prev = 0;
		delete temp;
		return;
	}
	DNode<T>* temp = head;
	DNode<T>*prevNode = 0;
	while (temp != 0 && temp->info!=val)
	{
		prevNode = temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	if (temp->next == 0)
	{
		prevNode->next = 0;
		delete temp;
		return;
	}
	prevNode->next = temp->next;
	temp->next->prev = prevNode;
	delete temp;
}
template <typename T>
void LDLL<T>::removeAtHead()
{
	if (head == 0)
	{
		return;
	}
	DNode<T>*temp = head;
	head = temp->next;
	temp->next->prev = 0;
	delete temp;
	return;
}
template <typename T>
void LDLL<T>::removeAtTail()
{
	if (head == 0)
	{
		return;
	}
	DNode<T>*prevNode = 0;
	DNode<T> * temp = head;
	while (temp->next != 0)
	{
		prevNode = temp;
		temp = temp->next;
	}
	prevNode->next = 0;
	delete temp;
}
template <typename T>
void LDLL<T>::removeAfter(T val)
{
	if (head == 0)
	{
		return;
	}
	DNode<T>* temp = head;
	DNode<T>*prevNode = 0;
	while (temp != 0 && temp->info!=val)
	{
		prevNode = temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	if (temp->next == 0)
		return;
	prevNode = temp;
	temp = temp->next;
	if (temp->next == 0)
	{
		prevNode->next = 0;
		delete temp;
		return;
	}
	prevNode->next = temp->next;
	prevNode->next->prev = prevNode;
	delete temp;

}
template <typename T>
void LDLL<T>::removeBefore(T val)
{
	if (head == 0)
	{
		return;
	}
	DNode <T> * temp = head;
	if (temp->info == val)
	{
		return;
	}
	
	DNode <T>* prevNode = head;
	while (temp != 0 && temp->info!=val)
	{
		prevNode = temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	temp->prev = prevNode->prev;
	temp->prev->next = prevNode->next;
	delete prevNode;
	return;
}
template LDLL < int > ;