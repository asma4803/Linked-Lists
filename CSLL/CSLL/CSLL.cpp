#include <iostream>
using namespace std;
#include "CSLL.h"
template <typename T>
CSLL<T>::CSLL()
{
	head = 0;
}
//template <typename T>
template <typename T>
CSLL<T>::~CSLL()
{
	Node<T>*q = head;
	head = head->next;
	do  
	{
		delete q;
		q = head;
		head = head->next;
	} while (head != head);
}
template <typename T>
CSLL<T> & CSLL<T>::operator=(const CSLL & ref)
{
	if (ref.head == 0)
	{
		head = 0;
		return *this;
	}
	Node<T> * frd = ref.head;
	Node<T>* copy = new Node<T>(frd->info);
	frd = frd->next;
	head = copy;
	copy->next = head;
	do
	{
		copy->next = new Node<T>(frd->info);
		copy = copy->next;
		copy->next = head;
		frd = frd->next;
	} while (frd != ref.head);
	return *this;
}
template <typename T>
CSLL<T>::CSLL(const CSLL & ref)
{
	if (ref.head == 0)
	{
		head = 0;
		return;
	}
	Node<T> * frd = ref.head;	
	Node<T>* copy = new Node<T>(frd->info);
	frd = frd->next;
	head = copy;
	copy->next = head;
	do
	{
		copy->next = new Node<T>(frd->info);
		copy = copy->next;
		copy->next = head;
		frd = frd->next;
	} while (frd != ref.head);
}
template <typename T>
void CSLL<T>::insertAtHead(T val)
{
	Node<T>* q = new Node<T>(val);
	if (head == 0)
	{
		head = q;
		q->next = head;
		return;
	}
	Node <T>* temp = head;
	do
	{
		temp = temp->next;
	} 
	while (temp != head);
	q->next = head;
	head = q;
	temp->next = head;
}

template <typename T>
void CSLL<T>::insertAtTail(T val)
{
	Node <T>* q = new Node<T>(val);
	if (head == 0)
	{
		head = q;
		q->next = head;
		return;
	}
	Node<T> * temp = head;
	do
	{
		temp = temp->next;
	} while (temp->next != head);
	q->next = head;
	temp->next = q;
}
template <typename T>
void CSLL<T>::insertAfter(T key , T val)
{
	if (head == 0)
	{
		return;
	}
	Node <T>* temp = head;
	Node <T>* q = new Node<T>(val);
	if (head->info == key)
	{
		q->next = temp->next;
		temp->next = q;
		return;
	}
	do
	{
		temp = temp->next;
	} while (temp->next != head && temp->info != key);

	q->next = temp->next;
	temp->next= q;
}
template <typename T>
void CSLL<T>::insertBefore(T key, T val)
{
	if (head == 0)
		return;
	Node <T>* temp = head;
	Node <T>* q = new Node<T>(val);
	if (head->info == key)
	{
		do
		{
			temp = temp->next;
		} while (temp->next != head);
		q->next = head;
		head = q;
		temp->next = head;
		return;
	}
	Node <T> * prevNode = 0;
	do
	{
		prevNode = temp;
		temp = temp->next;
	} while (temp->next != head && temp->info != key);
	if (!temp)
		return;
	q -> next = temp;
	prevNode->next = q;
}
template <typename T>
void CSLL<T>::remove(T val)
{
	if (head == 0)
		return;
	Node<T> * temp = head;
	Node <T>*temp2 = head;
	if (temp ->info == val)
	{
		do
		{
			temp2 = temp2->next;
		} while (temp2->next != head);
		head = temp->next;
		temp2->next = head;
		delete temp;
		return;
	}
	Node <T>* prevNode = head;
	do
	{
		prevNode = temp;
		temp = temp->next;
	} while (temp->next != head&& temp->info != val);
	if (!temp)
		return;
	prevNode->next = temp->next;
	delete temp;
}
template <typename T>
void CSLL<T>::removeAtHead()
{
	if (head == 0)
		return;
	Node<T> * temp = head;
	Node <T>*temp2 = head;
	do
	{
		temp2 = temp2->next;
	} while (temp2->next != head);
	head = temp->next;
	temp2->next = head;
	delete temp;
}
template <typename T>
void CSLL<T>::removeAtTail()
{
	if (head == 0)
		return;
	Node<T>* temp = head;
	Node<T>*preNode = 0;
	do
	{
		preNode = temp;
		temp = temp->next;
	} while (temp->next != head);
	preNode->next = temp->next;
	delete temp;
}
template <typename T>
void CSLL<T>::removeAfter(T val)
{
	Node<T>*temp = head;
	Node<T>*prevNode = 0;
	if (head == 0)
		return;
	if (temp->info == val && temp->next!=head)
	{
		prevNode = temp;
		temp = temp->next;
		prevNode->next = temp->next;
		delete temp;
		return;
	}
	do
	{
		prevNode = temp;
		temp = temp->next;
	} while (temp->next != head&& temp->info != val);
	if (!temp)
		return;
	if (temp->next == head && temp->info == val)
	{
		prevNode->next = temp->next;
		delete temp;
		return;
	}
	prevNode = temp;
	temp = temp->next;
	prevNode->next = temp->next;
	delete temp;
}
template <typename T>
void CSLL<T>::removeBefore(T val)
{
	if (head == 0)
		return;
	if (head->info == val)
		return;
	Node <T>* temp = head;
	Node <T>*prevNode = head;
	Node<T>* prevToPrevNode = 0;
	if (temp->next->info == val)
	{
		prevNode = temp;
		do
		{
			prevNode = prevNode->next;
		} while (prevNode->next != head);
		head = temp->next;
		prevNode->next = head;
		delete temp;
		return;
	}
	do
	{
		prevToPrevNode = prevNode;
		prevNode = temp;
		temp = temp->next;
	} while (temp->next != head && temp->info != val);
	if (!temp)
		return;
	prevToPrevNode->next = temp;
	delete prevNode;
}
template <typename T>
void CSLL<T>::display()
{
	Node <T>* temp = head;
	do
	{
		cout << temp->info << "->";
		temp = temp->next;
	} while (temp != head);
}
template CSLL < int > ;