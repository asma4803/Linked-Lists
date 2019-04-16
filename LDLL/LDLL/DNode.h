#include <iostream>
using namespace std;
#ifndef DNode_H
#define DNode_H
template <typename T>
class DNode
{
public:
	T info;
	DNode<T>* next;
	DNode<T>* prev;
	DNode();
	DNode(T);

};
#endif