#pragma once
#include"LinkedList.h"

template<class T> 
class Queue
{
public:
	Queue(int size)
	{
		assert(size > 0);
		m_Size = size;
	}
	~Queue(){}

	void Push(T item)
	{
		if (m_Items.GetSize() < m_Size)
		{
			m_Items.Push(item);
		}
	}
	void Pop()
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
	int m_Size;
	
};

