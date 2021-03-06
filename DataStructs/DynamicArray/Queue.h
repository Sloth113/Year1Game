#pragma once
#include "LinkedList.h"
template<class T>
class Queue
{
public:
	Queue()
	{
		m_list = LinkedList<T>();
	}
	Queue(int cap)
	{
		m_list = LinkedList<T>();
	}
	~Queue()
	{
		
	}

	bool empty()
	{
		return this->isEmpty();
	}
	bool isEmpty()
	{
		return m_list.count == 0;
	}
	int size()
	{
		return m_list.count();
	}
	void push(T value)
	{
		m_list.pushBack(value);
	}
	T pop()
	{
		return m_list.popFront();
	}
	T top()
	{
		T var = m_list.popFront();
		m_list.pushFront(var);
		return var;
	}

	
private:
	LinkedList<T> m_list;
};