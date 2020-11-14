#include <iostream>
#include "queue.h"
#include <string>

using namespace std;

int main()
{
	Stack_with_min<int> s(0);
	s.push(3); s.push(7); s.push(9); s.push(-7); s.push(10);
	for (size_t i = 0; i < 5; i++)
		cout << s[i] << '\t';
	cout << endl;
	cout << s.get_min();
	s.pop();
	std::cout << endl;
	std::cout << s.get_min();
	s.pop();
	std::cout << endl;
	std::cout << s.get_min();
	return 0;
}