#include <iostream>
using namespace std;
#include "Node.h"
template <typename T>
Node<T>::Node()
{
	next = 0;
}
template <typename T>
Node<T>::Node(T val)
{
	info = val;
	next = 0;
}
//template <typename T>
//Node<T>::~Node()
//{
//	if (next)
//	{
//		delete next;
//	}
//}

template Node < int > ;