#pragma once
#include "pch.h"
#include <string>
class Point
{
private:
	double m_x, m_y;
public:
	//Constructors
	Point(const double x, const double y) { set(x, y);}
	Point() { set(0, 0);} //don't use for initialisation of many points

	//Methods
	void set(const double a, const double b);
	void print() const;
	std::string toString() const;
	double getX() const { return m_x; }
	double getY() const { return m_y; }
	double getDistanceToPoint(const Point &p) const;
	const Point getMiddlePoint(const Point &p) const;
	double getZeroDistance() const;

	//Operators
	Point operator+(const Point &a) const { return Point(m_x + a.m_x, m_y + a.m_y); }
	Point operator-(const Point &a) const { return Point(m_x - a.m_x, m_y - a.m_y); }
	Point& operator+=(const Point &rhs) { *this = *this + rhs; return *this; }
	Point& operator-=(const Point &rhs) { *this = *this - rhs; return *this; }

	friend std::ostream& operator<<(std::ostream &out, const Point &p);
	friend std::istream& operator>>(std::istream &in, const Point &p);




};

