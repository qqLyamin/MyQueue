#include <iostream>
#include "MyQueue.h"


int main()
{
	MyQueue<int> m;
	int i = 1;
	m.push_back(i);

	std::cout << m.pop_back() << std::endl;
	system("pause");
	__asm nop
}