#pragma once
//double linked list with Node struct inside
template<typename T> class DLinkedList
{
private:
	struct Node {
		Node(const T& data) : m_data(data), m_next(nullptr), m_prev(nullptr) {}
		T m_data;
		Node *m_next, *m_prev;
		T& getData() { return m_data; }
	};
	//Node pointers for current, head and tail
	Node *m_cur, *m_head, *m_tail;
	int m_size;
public:
	class Iterator
	{
	public:
		Iterator(Node *p) :m_ptr(p) {}
		Iterator() {}
		Iterator& operator++() { m_ptr = m_ptr->m_next; return *this; }
		const T& operator*() { return m_ptr->m_data; }
		operator bool() { return m_ptr; }

	private:
		Node *m_ptr;
	};

	DLinkedList();
	DLinkedList(const DLinkedList &list) : m_head(nullptr), m_tail(nullptr), m_cur(nullptr) { *this = list; }
	DLinkedList& operator=(const DLinkedList &list);
	~DLinkedList() { clear(); }

	void insert(const T &data);
	void clear();
	int getSize(bool update);
	void appendAtTail(const T &data);
	void appendAfterCurrent(const T &data);
	void insertAsHead(const T &data);
	void push(const T &data);
	void enqueue(const T &data);
	bool moveToStart();
	bool moveForward();
	Iterator getStartIt() { return Iterator(m_head); }

	void printFromHead() const;
	void printFromTail() const;
	const T* getCurrentNode() const;
	const T getCurrentNodeData() const;

};

//IMPLEMENTATION
template<typename T>
DLinkedList<T>::DLinkedList() :m_head(nullptr), m_cur(nullptr), m_tail(nullptr), m_size(0) {}

template<typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T> &list)
{
	if (&list == this)
		return *this;

	clear();
	Node *temp = list.m_head;
	while (temp)
	{
		appendAtTail(temp->getData());
		temp = temp->m_next;
	}
	return *this;
}

template<typename T>
void DLinkedList<T>::insert(const T& data)
{
	Node *temp = new Node(data);
	if (m_cur && m_cur->m_prev)
	{
		m_cur->m_prev->m_next = temp;
	}

	temp->m_prev = m_cur ? m_cur->m_prev : nullptr;

	if (m_cur)
	{
		m_cur->m_prev = temp;
	}

	temp->m_next = m_cur;
	m_cur = temp;

	if (!temp->m_prev)
		m_head = temp;
	if (!temp->m_next)
		m_tail = temp;
}

template<typename T>
void DLinkedList<T>::appendAfterCurrent(const T& data)
{
	Node *temp = new Node(data);
	if (m_cur && m_cur->m_next)
	{
		m_cur->m_next->m_prev = temp;
	}
	temp->m_next = m_cur ? m_cur->m_next : nullptr;

	if (m_cur)
		m_cur->m_next = temp;

	temp->m_prev = m_cur;
	m_cur = temp;

	if (!temp->m_prev)
		m_head = temp;
	if (!temp->m_next)
		m_tail = temp;
}

template<typename T>
void DLinkedList<T>::printFromHead() const
{
	Node *temp = m_head;
	std::cout << "List: [";
	while (temp)
	{
		std::cout << temp->m_data << ";";
			temp = temp->m_next;
	}
	std::cout << " ]" << std::endl;
}


template<typename T>
void DLinkedList<T>::printFromTail() const
{
	Node *temp = m_tail;
	std::cout << "List: [";
	while (temp)
	{
		std::cout << temp->m_data << ";";
			temp = temp->m_prev;
	}
	std::cout << " ]" << std::endl;
}

template<typename T>
int DLinkedList<T>::getSize(bool update)
{
	if (!update)
		return m_size;

	int size = 0;
	Node *temp = m_head;
	while (temp)
	{
		size++;
		temp = temp->m_next;
	}
	m_size = size;
	return size;
}

template<typename T>
const T* DLinkedList<T>::getCurrentNode() const
{
	return m_cur;
}

template<typename T>
const T DLinkedList<T>::getCurrentNodeData() const
{
	return m_cur->getData();
}

template<typename T>
void DLinkedList<T>::appendAtTail(const T &data)
{
	if (!m_head)
	{
		appendAfterCurrent(data);
	}
	else
	{
		Node *temp = new Node(data);
		m_tail->m_next = temp;
		temp->m_prev = m_tail;
		m_tail = temp;
	}
}

template<typename T>
void DLinkedList<T>::insertAsHead(const T &data)
{
	if (!m_head)
		insert(data);
	else
	{
		Node *temp = new Node(data);
		m_head->m_prev = temp;
		temp->m_next = m_head;
		m_head = temp;
	}
}

template<typename T>
void DLinkedList<T>::push(const T &data)
{
	insertAsHead(data);
}


template<typename T>
void DLinkedList<T>::enqueue(const T &data)
{
	appendAtTail(data);
}

template<typename T>
void DLinkedList<T>::clear()
{
	Node *temp;
	while (m_head != nullptr)
	{
		temp = m_head;
		m_head = m_head->m_next;
		delete temp;
	}
	m_head = nullptr;
	m_cur = nullptr;
	m_tail = nullptr;
	getSize(true);
}

template<typename T>
bool DLinkedList<T>::moveToStart()
{
	if (m_cur && m_head)
	{
		m_cur = m_head;
		return true;
	}
	return false;
}


template<typename T>
bool DLinkedList<T>::moveForward()
{
	if (m_cur && m_cur->m_next)
	{
		m_cur = m_cur->m_next;
		return true;
	}
	return false;
}






























