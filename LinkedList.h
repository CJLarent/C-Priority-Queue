#pragma once
#include<cassert>
// type names 
template <class T> class LinkIterator;
template<class T> class LinkedList;
// template classes refs 
template <class T>
class LinkNode
{
public:// friends are trusted with priavte data 
	friend class LinkIterator<T>;
	friend class LinkedList<T>;
	
private:
	T m_Data;
	LinkNode* m_Next;

};

template <class T>

class LinkIterator
{
public:
	LinkIterator()
	{
		m_Node = nullptr;
	}
	~LinkIterator() {}

	void operator=(LinkNode<T>* node)
	{
		m_Node = node;
	}
	T& operator*()
	{
		assert(m_Node != nullptr);

		// derefering to get the node data 
		return m_Node->m_Data;
	}
	void operator++() // prefix 
	{
		assert(m_Node != nullptr);
		// derefer to get the next node 
		m_Node = m_Node->m_Next;
	}
	void operator++(int)// postfix
	{
		assert(m_Node!+ nullptr);
		m_Node = m_Node->m_Next;
	}
	bool operator!=(LinkNode<T>* node)
	{
		return(m_Node != node);
	}

	bool operator==(LinkNode<T>* node)
	{
		return(m_Node == node);
	}
private:
	LinkNode<T>* m_Node;
};

template <class T>

class LinkedList

{
public:
	LinkedList(): m_Size(0),m_Root(nullptr),m_LastNode(nullptr)
	{

	}
	~LinkedList()
	{
		while (m_Root)
		{
			//Pop()
		}
	}

	LinkNode<T>* Begin()
	{
		assert(m_Root != nullptr);
		return m_Root;
	}
	LinkNode<T>* End()
	{
		return nullptr;
	}
	LinkNode<T>* Last()
	{
		assert(m_LastNode != nullptr);
		return m_LastNode;
	}

	void Push(T NewItem)
	{
		LinkNode<T>* node = new LinkNode<T>;
		assert(node != nullptr);
		node->m_Data = NewItem;
		node->m_Next = nullptr;

		if (m_LastNode != nullptr)
		{
			m_LastNode->m_Next = node;
			m_LastNode = node;
		}
		else
		{
			m_Root = node;
			m_LastNode = node;
		}

		m_Size++;
	}
	void Pop()
	{
		assert(m_Root != nullptr);
		if (m_Root->m_Next == nullptr)
		{
			delete m_Root;
			//delete m_LastNode;
			m_Root = nullptr;
			m_LastNode = nullptr;
		}
		else
		{
			LinkNode<T>* prevNode = m_Root;

			while (prevNode->m_Next != nullptr && prevNode->m_Next != m_LastNode)
			{
				prevNode = prevNode->m_Next;
			}

			delete m_LastNode;
			prevNode->m_Next = nullptr;
			m_LastNode = prevNode;
			prevNode = nullptr;

		}
		m_Size = (m_Size == 0 ? m_Size : m_Size - 1);

		int GetSize()
		{
			return m_Size;
		}
	}
private:
	int m_Size;
	int m_ItemNumber;
	LinkNode<T>* m_Root;
	LinkNode<T>* m_LastNode;

};
