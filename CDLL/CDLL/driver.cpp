#include <iostream>
using namespace std;
#include "CDLL.h"
int main()
{
	CDLL<int> c1;
	c1.insertAtHead(2);
	c1.insertAtHead(1);
	c1.insertAtHead(0);
	c1.insertAtTail(3);
	c1.insertAtTail(4);
	c1.insertAfter(4, 5);
	c1.insertAfter(5, 6);
	c1.insertAfter(6, 7);
	c1.insertAfter(6, 8);
	c1.insertBefore(7, 10);
	c1.remove(4);
	c1.removeAtHead();
	c1.removeAtTail();
	c1.removeAfter(1);
	c1.removeBefore(7);
	c1.display();
	CDLL<int> c2;
	c2 = c1;
	cout << "\n";
	c2.display();
	return 1;
}