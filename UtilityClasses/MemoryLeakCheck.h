#pragma once
class MemoryLeakCheck
{
	static int s_objectCounter;
	static int s_vectorCounter;

public:
	~MemoryLeakCheck();
	friend void *operator new(size_t size);
	friend void *operator new[](size_t size);
	friend void operator delete(void *p);
	friend void operator delete[](void *p);
};