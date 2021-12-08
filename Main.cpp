#include<iostream>
#include<string.h>
#include"LinkedList.h"
#include"priority queue.h"

using namespace std;

int main()
{

	

	const int SIZE = 8;
	Dequeue<int> intQue(SIZE);

		int proity = 0;


	for (int i = 0; i < SIZE; i++)
	{
		intQue.Push(20 + i,proity);

		proity++;
	}
	cout << "Items in the Queue" << intQue.GetSize() << endl;

	while (intQue.IsEmpty() == false)
	{
		cout << "Front" << intQue.Front() << endl;
		cout << "Back" << intQue.Back() << endl;
		cout << "Proity"<< proity << endl;
		cout << endl;
		proity--;
		intQue.Pop();
	}
	if (intQue.IsEmpty() == true)
	{
		cout << "The queue is empty" << endl;
	}
	else
	{
		cout << "The queue is not empty!!!" << endl;
	}

	

	
	return 0;

}