#include <iostream>
using namespace std;
#include "LDLL.h"
int main()
{
	LDLL<int> l1;
	l1.insertAtHead(12);
	l1.insertAtHead(13);
	l1.insertAtTail(14);
	l1.insertAtTail(15);
	l1.insertAfter(15, 18);
	l1.insertBefore(13, 35);
	l1.remove(35);
	/*l1.removeAtHead();
	l1.removeAtTail();
	l1.removeAfter(14);*/
	l1.removeBefore(18);
	return 1;
}