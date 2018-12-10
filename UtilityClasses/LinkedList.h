#pragma once
#include "pch.h"
#include "Node.h"
#include <string>
//SINGLE LINKED LIST

template<typename T> class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList &list) : m_head(nullptr), m_total(0) { *this = list; }
	LinkedList& operator=(const LinkedList &list);
	~LinkedList();
	/********************************************************************/
	/* Adds the given object through LIFO principle to the list */
	/* Input: data, Output: Boolean - true if successful
	/* Pre: N/A ; Post: N/A	
	/********************************************************************/
	bool add(T* data);
	/********************************************************************/
	/* Clears list by deleting each element. */
	/* Pre: N/A ; Post: Empty list, no leaks.
	/********************************************************************/
	void clear();
	
	bool remove();

	int getSize() const;

private:
	Node<T>* m_head;
	int m_total;
};

/********************************************************************/
//IMPLEMENTATION
/********************************************************************/

template<typename T>
LinkedList<T>::LinkedList() : m_head(nullptr), m_total(0)
{}

template<typename T>
bool LinkedList<T>::add(T* data)
{
	Node<T>* temp = new Node<T>(data);
	if (!temp)
		return false;
	
	temp->m_next = m_head;
	m_head = temp;
	++m_total;
	return true;
}

template<typename T>
void LinkedList<T>::clear()
{
	Node<T>* temp;
	while (m_head != nullptr)
	{
		temp = m_head;
		m_head = m_head->m_next;
		delete temp;
	}
	m_total = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() { clear(); }

template<typename T>
bool LinkedList<T>::remove()
{
	if (!m_head)
		return false;
	else
	{
		Node<T> temp = m_head;
		m_head = m_head->m_next;
		delete temp;
		--m_total;
		return true;
	}
}


template <typename T>
int LinkedList<T>::getSize() const
{
	return m_total;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &list)
{
	if (&list == this)
		return *this;
	   	 
	clear();
	while (list.m_head)
	{
		add(list.m_head->m_data);
		list.m_head = list.m_head->m_next;
	}


	return *this;
}