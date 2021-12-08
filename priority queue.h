#pragma once
#include"LinkedList.h"

template<class T> 
class Dequeue
{
public:
	Dequeue(int size)
	{
		assert(size > 0);
		m_Size = size;
	}
	~Dequeue(){}

	void Push(T item, int proity  )// pushing the back 
	{

		
		m_Items.Push(item,proity);
			m_Size++;
			m_Proity++;
	}
	void Pop() // pop from the fornt 
	{
		m_Items.PopFornt();
	}
	T& Front()
	{
		LinkIterator<T>step;
		step = m_Items.Begin();

		return*step;
	}
	T& Back()
	{
		LinkIterator<T>step;
		step = m_Items.Last();

		return*step;
	}
	int GetSize()
	{
		return m_Items.GetSize();
	}

	int GetMaxSize()
	{
		return m_Size;
	}

	bool IsEmpty()
	{
		return(m_Items.GetSize() == 0);
	}

	void Resize(int size)
	{
		assert(size > 0);
		m_Size = size;
	}
	
private:
	LinkedList<T>m_Items;
	//LinkedList<T>m_Root;
	int m_Proity;
	int m_Size;
	
};

