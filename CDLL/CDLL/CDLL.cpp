#include <iostream>
using namespace std;
#include "CDLL.h"
template <typename T>
CDLL<T>::CDLL()
{
	head = 0;
}
template <typename T>
CDLL<T>::CDLL(const CDLL & ref)
{
	if (ref.head == 0)
	{
		head = 0;
		return;
	}
	DNode<T> * frd = ref.head;
	DNode<T>* copy = new DNode<T>(frd->info);
	frd = frd->next;
	head = copy;
	copy->next = head;
	do
	{
		copy->next = new DNode<T>(frd->info);
		copy = copy->next;
		copy->next = head;
		frd = frd->next;
	} while (frd != ref.head);
}
template <typename T>
CDLL<T>::~CDLL()
{
	DNode<T>*q = head;
	head = head->next;
	do
	{
		delete q;
		q = head;
		head = head->next;
	} while (head != head);
}
template <typename T>
CDLL<T> & CDLL<T>::operator=(const CDLL & ref)
{
	if (ref.head == 0)
	{
		head = 0;
		return *this;
	}
	DNode<T> * frd = ref.head;
	DNode<T>* copy = new DNode<T>(frd->info);
	frd = frd->next;
	head = copy;
	copy->next = head;
	do
	{
		copy->next = new DNode<T>(frd->info);
		copy = copy->next;
		copy->next = head;
		frd = frd->next;
	} while (frd != ref.head);
	return *this;
}
template <typename T>
void CDLL<T>::insertAtHead(T val)
{
	DNode<T>* q = new DNode<T>(val);
	if (head == 0)
	{
		head = q;
		q->next = head;
		head->prev = q;
		return;
	}
	q->prev = head->prev;
	q->next = head;
	head->prev->next = q;
	head->prev = q;
	head = q;
}
template <typename T>
void CDLL<T>::insertAtTail(T val)
{
	DNode<T>* q = new DNode<T>(val);
	if (head == 0)
	{
		head = q;
		q->next = head;
		head->prev = q;
		return;
	}
	head->prev->next = q;
	head->prev = q;
	q->next = head;	
}
template <typename T>
void CDLL<T>::insertAfter(T key, T val)
{
	if (head == 0)
		return;
	DNode<T>* temp = head;
	DNode <T>* q = new DNode<T>(val);
	do
	{
		temp = temp->next;
	} while (temp != head && temp->info != key);
	if (!temp)
		return;
	q->prev = temp;
	q->next = temp->next;
	temp->next->prev = q;
	temp->next = q;
	
}
template <typename T>
void CDLL<T>::insertBefore(T key, T val)
{
	if (head == 0)
		return;
	DNode<T>* temp = head;
	DNode<T>*prevNode = head;
	DNode <T>* q = new DNode<T>(val);
	if (temp->info == key)
	{
		temp->prev->next = q;
		q->next = temp;
		q->prev = temp->prev;
		temp->prev = q;
		head = q;
		return;
	}
	do
	{
		prevNode = temp;
		temp = temp->next;
	} while (temp != head && temp->info != key);
	if (!temp)
		return;
	q->next = temp;
	q->prev = prevNode;
	temp->prev = q;
	prevNode->next = q;
}
template <typename T>
void CDLL<T>::remove(T val)
{
	if (head == 0)
		return;
	DNode <T>* temp = head;
	DNode<T>*preNode = head; 
	if (temp->info == val)
	{
		temp->prev->next = temp->next;
		head = temp->next;
		delete temp;
		return;
	}
	do
	{
		preNode = temp;
		temp = temp->next;
	} while (temp != head&& temp->info != val);
	if (!temp)
		return;
	if (temp->info == val&& temp->next == head)
	{
		temp->prev->next = temp->next;
		delete temp;
		return;
	}
	preNode->next = temp->next;
	temp->next->prev = preNode;
	delete temp;
}
template <typename T>
void CDLL<T>::removeAtHead()
{
	if (head == 0)
		return;
	DNode<T>* temp = head;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	head = temp->next;
	delete temp;
}
template <typename T>
void CDLL<T>::removeAtTail()
{
	if (head == 0)
		return;
	DNode<T>*temp = head;
	temp->prev->prev->next = head;
	delete temp->prev;
}
template <typename T>
void CDLL<T>::removeAfter(T val)
{
	if (head == 0)
		return;
	DNode<T>* temp = head;
	DNode<T>* prevNode = 0;
	do
	{
		prevNode = temp;
		temp = temp->next;
	} while (temp != head && temp->info != val);
	if (!temp)
		return;
	prevNode = temp;
	temp = temp->next;
	if (temp == head)
		return;
	temp->next->prev = prevNode;
	prevNode->next = temp->next;
	delete temp;
}
template <typename T>
void CDLL<T>::removeBefore(T val)
{
	if (head == 0)
		return;
	if (head->info == val)
		return;
	DNode<T>* temp = head;
	DNode<T>* prevNode = 0;
	DNode<T>* prevToPrevNode = 0;
	if (temp->next->info == val)
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		head = temp->next;
		delete temp;
		return;
	}
	do
	{
		prevToPrevNode = prevNode;
		prevNode = temp;
		temp = temp->next;
	} while (temp != head && temp->info != val);

	temp->prev = prevNode->prev;
	prevToPrevNode->next = temp;
	delete prevNode;
}
template <typename T> 
void CDLL<T>::display()
{
	DNode<T>* temp = head;
	do
	{
		cout << temp->info << "->";
		//cout << temp->next << "  " << temp->prev << " | ";
		temp = temp->next;
	} while (temp != head);
}
template CDLL < int > ;