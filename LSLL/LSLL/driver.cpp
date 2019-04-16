#include <iostream>
using namespace std;
#include "LSLL.h"
int main()
{
	LSLL<int> l;
	l.insertAtHead(12);
	l.insertAtTail(19);
	l.insertAtHead(13);
	l.insertAtHead(16);
	l.insertAfter(16, 18);
	/*l.insertBefore(16, 87);
	l.remove(18);
	l.removeAtHead();
	l.removeAtTail();
	l.removeAfter(13);
	l.insertAtTail(17);
	l.removeBefore(17);*/
	return 1;
}