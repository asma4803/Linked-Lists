#include <iostream>
using namespace std;
#include <string>
#ifndef KeyNotFound_H
#define KeyNotFound_H
class KeyNotFound:public exception
{
	string msg;
public:
	KeyNotFound()
	{}
	KeyNotFound(string str) :msg(str)
	{}
	const char*what()
	{
		return msg.c_str();
	}
	void operator +=(string str)
	{
		msg +=str;
	}
};
#endif