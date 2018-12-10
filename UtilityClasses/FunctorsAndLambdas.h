#pragma once
#include "pch.h"
#include "MyException.h"

//PREDICATE
class Add
{
private:
	int m_value;
public:
	Add(int v):m_value(v){}
	bool operator()(int &v) 
	{
		v += m_value;
		return true;
	}
};


//Functor
template<typename T>
class RemoveNegatives
{
public:
	RemoveNegatives() {};
	bool operator()(T &v)
	{
		return v < 0;
	}
};


//FUNCTION POINTER TEMPLATE
template<typename T>
bool removePositiveValues(const T &a)
{
	return a > 0;
}



template<typename T>
bool insert_Element(T arr[], size_t max, size_t &akt, const T &neu)
{
	if (akt > max)
		throw OutOfBoundException(max, akt);
	arr[akt] = neu;
	++akt;
	return true;
}


template<typename T, typename F>
bool removeAllElementsLike(T arr[], size_t &akt, F predicate)
{
	size_t i = 0, j = 0;
	for (; i < akt; ++i)
	{
		if (!predicate(arr[i]))
		{
			arr[j] = arr[i];
			++j;
		}
	}

	size_t diff = i - j;
	akt -= diff;
	return diff > 0 ? true : false;
}


//LAMBDA EXPRESSION EXAMPLE
//can be used instead of predicates
template<typename T>
void lambda()
{
	auto lambda = [](T a) ->bool {return a > 0; }
}

template<typename T>
auto getHalfVal(T w) ->decltype(w)
{
	if (w > 0)
		return w / 2;
	return 0;
}

template<typename T, typename F>
void doSomething(T v[], int &akt, F fkt)
{
	for (int i = 0; i < akt, ++i)
	{
		fkt(v[i], akt);
		//depending on the predicate -> change akt...
	}
}


//LAMDA EXPLANATIONS && DECLTYPE
void explainLambda()
{


	//Bindung & Aussage
	//->int definiert rückgabewert (nicht notwendig bei void und 1, sonst immer
	int(*f)(int, int) = [](int a, int b)->int {return a + b; };
	//bei der Bindung können parameter ausm stack übergeben werden als kopie oder referenz
	//& für alle als referenz, = für alle als kopie
	//[&] && [=]
	//[=, &a] -> alle als kopie ausser a als referenz usw.
	auto pred = [](int a, int b) {return a < b; };

	decltype(4.0) a = 5.0; //determines the type automatically



}