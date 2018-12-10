#pragma once
#include "pch.h"
#include <exception>
#include <string>

class OutOfBoundException : public std::exception
{
public:
	int m_size, m_current;
	OutOfBoundException(int v1, int v2) : exception(), m_size(v1), m_current(v2){}
	virtual const char *what() const override {
		std::string temp;



		temp += "\0";
		return temp.c_str();
	}
};