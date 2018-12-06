#include "MemoryLeakCheck.h"
#include <iostream>

int MemoryLeakCheck::s_objectCounter;
int MemoryLeakCheck::s_vectorCounter;

MemoryLeakCheck::~MemoryLeakCheck()
{
	std::cout << "Not destroyed objects: " << s_objectCounter << std::endl;
	std::cout << "Not destroyed vectors:" << s_vectorCounter << std::endl;

}

void *operator new(size_t size) { ++MemoryLeakCheck::s_objectCounter; return malloc(size); }
void *operator new[](size_t size) {++MemoryLeakCheck::s_vectorCounter; return malloc(size);}
void operator delete(void *p) { --MemoryLeakCheck::s_objectCounter; return free(p); }
void operator delete[](void *p) {--MemoryLeakCheck::s_vectorCounter; return free(p); }


//Call this class in the main like 
//MemoryLeakCheck memCheck;
//Will count news and deletes and tells the number of memory leaks created