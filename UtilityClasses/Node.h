#pragma once
#include "pch.h"
#include "LinkedList.h"

template<typename T> class LinkedList;
template<typename T> class Node
{
	friend class LinkedList<T>;
public:
	Node(T* data);
	~Node();
	//Assignment and Copy Constructor required!

private:
	T* m_data;
	Node<T>* m_next;
};

//Implementation

template<typename T>
Node<T>::Node(T* data) : m_data(data), m_next(nullptr)
{}

template<typename T>
Node<T>::~Node() {
	//delete m_data;
}