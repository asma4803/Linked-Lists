#include <iostream>
using namespace std;
#include "DNode.h"
template <typename T>
DNode<T>::DNode()
{
	next = 0;
	prev = 0;
}
template <typename T>
DNode<T>::DNode(T val)
{
	info = val;
	next = 0;
	prev = 0;
}
template DNode < int >;