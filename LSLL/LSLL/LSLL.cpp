#include <iostream>
using namespace std;
#include "LSLL.h"
#include "KeyNotFound.h"
template <typename T>
LSLL<T>::LSLL()
{
	head = 0;
}
template <typename T>
LSLL<T>::~LSLL()
{
	Node<T>*q = head;
	head = head->next;
	while (head != 0)
	{
		delete q;
		q = head;
		head = head->next;
	}
}
template <typename T>
LSLL<T> & LSLL<T>::operator =(const LSLL & ref)
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
	Node<T> * frd = ref.head;
	Node<T>* copy = new Node<T>(frd->info);
	frd = frd->next;
	head = copy;
	while (frd != 0)
	{
		copy->next = new Node<T>(frd->info);
		copy = copy->next;
		frd = frd->next;
	}
	return *this;
}
template <typename T>
LSLL<T>::LSLL(const LSLL & ref)
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
	while (frd != 0)
	{
		copy->next = new Node<T>(frd->info);
		copy = copy->next;
		frd = frd->next;
	}
}
template <typename T>
void LSLL<T>::insertAtHead(T val) //  O(1)
{
	Node<T>*q = new Node<T>(val);   
	q->next = head;
	head = q;
}
template <typename T>
void LSLL<T>::insertAtTail(T val) //O(N)
{
	if (head == 0)
	{
		head = new Node<T>(val);
		return;
	}
	Node<T>* q = head;
	while (q->next != 0)
	{
		q = q->next;
	}
	q->next = new Node <T>(val);
}
template <typename T>
void LSLL<T>::insertAfter(T key, T val) //O(N)
{
	
	if (head == 0)
	{
		return;
	}
	Node<int>*q = new Node<int>(val);
	if (head->info == key)
	{
		q->next = head->next;
		head->next = q;
		return;
	}
	Node <int> *temp = head;
	while (temp !=0 && temp->info != key)
	{
		temp = temp->next;
	}
	if (!temp)
		return;
	q->next = temp->next;
	temp->next = q;
	return;
}
template <typename T>
void LSLL<T>::insertBefore(T key,T val)
{
	if (head == 0)
	{
		return;
	}
	Node<T>*q = new Node<T>(val);
	if (head->info == key)
	{
		q->next = head;
		head = q;
		return;
	}
	Node <T> *temp;
	Node<T>* prev;
	temp = head;
	prev = head;
	while (temp != 0 && temp->info!=key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	q->next = temp;
	prev->next = q;
	return;
}
template <typename T>
void LSLL<T>::remove(T key)
{
	if (head == 0)
	{
		return;
	}
	Node <T>*prev;
	Node<T>*temp;
	prev = head;
	temp = head;
	while (temp != 0 && temp->info!=key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	prev->next = temp->next;
	delete temp;
	return;
}
template <typename T>
void LSLL<T>::removeAtHead() //O(1)
{
	if (head == 0)
		return;
	Node<T>*temp = head;
	head = temp->next;
	delete temp;
}
template <typename T>
void LSLL<T>::removeAtTail()  //O(N)
{
	if (head == 0)
	{
		return;
	}
	Node<T> * temp;
	temp = head;
	Node<T>* prev;
	prev = head;
	while (temp->next != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = 0;
	delete temp;
}
template <typename T>
void LSLL<T>::removeAfter(T val)
{
	if (head == 0)
	{
		return;
	}
	Node<T> *temp;
	Node<T>* prev;
	temp = head;
	prev = head;
	while (temp != 0 && temp->info!= val)
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	prev = temp;
	temp = temp->next;
	prev->next = temp->next;
	delete temp;
}
template <typename T>
void LSLL<T>::removeBefore(T val)
{
	if (head == 0)
		return;
	if (head->info== val)
	{
		return;
	}
	Node<T> *temp = head;
	Node<T>* prevToPrevNode = 0;
	Node<T>* prev = 0;
	if (head->next->info == val)
	{
		head = temp->next;
		delete temp;
		return;
	}
	while (temp != 0 && temp->info!=val)
	{
		prevToPrevNode = prev;
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	prevToPrevNode->next = temp;
	delete prev;
}
//template <typename T>
//LSLL<T>::Iterator::Iterator()
//{
//	list = 0;
//	curr = 0;
//}
//template <typename T>
//LSLL<T>::Iterator::Iterator(LSLL<T>* l)
//{
//	list = l;
//	curr = l->head;
//}
//template <typename T>
//T & LSLL<T>::Iterator::operator *()
//{
//	if (curr)
//	{
//		return curr->info;
//	}
//	else
//		throw KeyNotFound("Key Not found");
//}
//template <typename T>
//void LSLL<T>::Iterator::next()
//{
//	if (curr)
//	{
//		curr = curr->next;
//	}
//}
//template <typename T>
//bool LSLL<T>::Iterator::isDone()
//{
//	return curr == 0;
//}
//template <typename T>
//void LSLL<T>::Iterator::setList(LSLL <T>* l)
//{
//	list = l;
//	curr = l->head;
//}
//template <typename T>
//void LSLL<T>::Iterator::start()
//{
//	if (list)
//		curr = list->head;
//}
//

template LSLL < int > ;