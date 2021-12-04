#pragma once
#include<vector>
using namespace std;

template <class T>

class Heap
{
public:
	Heap() {}

	Heap(int MinSize)
	{
		m_Heap.reserve(MinSize);
	}
	void Push(T key)
	{
		m_Heap.push_back(key);

		int Index = (int)m_Heap.size() - 1;// using staic cast 
		T temp=m_Heap[Index];

		int PairentIndex = (Index - 1) / 2;// find the pairent node 

		while (Index > 0 && temp >=m_Heap[PairentIndex] )
		{
			m_Heap[Index] = m_Heap[PairentIndex];
			Index = PairentIndex;
			PairentIndex = (Index - 1) / 2;
		}
		m_Heap[Index] = temp;
	}

	void pop()
	{
		int Index = 0;
		m_Heap[Index] = m_Heap[(int)m_Heap.size() - 1];
		m_Heap.pop_back();

		if ((int)m_Heap.size() > 0)
		{
			T temp = m_Heap[Index];
			int CurrentIndex = 0, LeftIndex = 0, RigtIndex = 0;

			while (Index < (int)m_Heap.size() / 2)
			{
				LeftIndex = 2 * Index + 1;
				RigtIndex = LeftIndex + 1;

				if (RigtIndex < (int)m_Heap.size() && m_Heap[LeftIndex] < m_Heap[RigtIndex])
				{
					CurrentIndex = RigtIndex;
				}
				else
				{
					CurrentIndex = LeftIndex;
				}
				if (temp >= m_Heap[CurrentIndex])
				{
					break;
				}
				m_Heap[Index] = m_Heap[CurrentIndex];

				Index = CurrentIndex;
			}
			m_Heap[Index] = temp;
		}
	}
			


		
		T Peek()
		{
			return m_Heap[0];
		}

		int Size()
		{
			return m_Heap.size();
		}
	

private:

	vector<T> m_Heap;
};