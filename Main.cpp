#include<iostream>
#include<string.h>
#include"LinkedList.h"
#include"priority queue.h"
#include<time.h>
#include<math.h>
using namespace std;

int main()
{
	clock_t Time;
	Time = clock();
	LinkedList<int>LList;
	LList.Push(65);
	LList.Pop();
	LList.Push(9);
	LList.PushFront(17);
	LList.PushFront(4);
	LList.Push(51);
	LList.PopFornt();
	LList.Push(40);
	

	LinkIterator<int>LT;
	for (LT = LList.Begin(); LT != LList.End(); LT++)
	{
		cout << "" << *LT << endl;
	}

	for (LT = LList.Begin(); LT != nullptr; LT--)
	{
		cout << "" << *LT << endl;
	}
	cout << endl;

	const int SIZE = 8;
	Queue<int> intQue(SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		intQue.Push(20 + 2);
	}
	cout << "Items in the Queue" << intQue.GetSize() << endl;

	while (intQue.IsEmpty() == false)
	{
		cout << "Front" << intQue.Front() << endl;
		cout << "Back" << intQue.Back() << endl;
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