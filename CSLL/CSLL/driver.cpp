#include <iostream>
using namespace std;
#include "CSLL.h"
int main()
{
	CSLL<int> c1;
	c1.insertAtHead(2);
	c1.insertAtHead(1);
	c1.insertAtTail(3);
	c1.insertAfter(1, 4);
	c1.insertBefore(1, 6);
	/*c1.remove(3);
	c1.removeAtHead();
	c1.removeAtTail();
	c1.removeAfter(1);*/
	c1.removeBefore(2);
	c1.display();
	CSLL<int> c2;
	c2 = c1;
	cout << "\n";
	c2.display();
	
	return 1;
}