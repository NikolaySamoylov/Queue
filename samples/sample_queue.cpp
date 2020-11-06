#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
	Queue<int> q(4);
	for (size_t i = 0; i < 4; i++)
		q[i] = i + 1;
	cout << q.front() << ' ' << q.back() << endl;
	q.pop();
	q.pop();
	q.pop();
	cout << endl << q.front() << ' ' << q.back() << endl;
	q.push(5);
	q.push(6);
	q.push(7);
	cout << endl << q.size() << ' ' << q.capacity() << endl;
	cout << endl << q.full() << endl;
	q.push(8);
	cout << endl << q.front() << ' ' << q.back() << endl;
	cout << endl << q.empty() << endl;
	cout << endl;
	for (size_t i = 0; i < 5; i++)
		cout << q[i] << endl;
	cout << endl << q.front() << ' ' << q.back();
	return 0;
}