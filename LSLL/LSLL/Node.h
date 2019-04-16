#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
template <typename T>
class Node
{
public:
	T info;
	Node<T> * next;
	Node();
	Node(T val);
//	~Node();
};
#endif