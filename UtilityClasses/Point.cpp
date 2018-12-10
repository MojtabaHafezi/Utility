#include "pch.h"
#include "Point.h"
#include <iostream>
#include <sstream>
#include <algorithm>

void Point::set(const double x, const double y)
{
	m_x = x;
	m_y = y;
}

void Point::print() const
{
	std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
}

double Point::getZeroDistance() const
{
	return sqrt(m_x*m_x + m_y * m_y);
}

double Point::getDistanceToPoint(const Point &p) const
{
	return sqrt(pow((m_x - p.m_x), 2) + pow((m_y - p.m_y), 2));
}

const Point Point::getMiddlePoint(const Point &p) const
{
	double x, y;
	x = (m_x + p.m_x) / 2;
	y = (m_y + p.m_y) / 2;
	return Point(x, y);
}

std::string Point::toString() const
{
	std::stringstream temp;
	temp << "(" << m_x << ", " << m_y << ")";
	return temp.str();
}

std::ostream& operator<<(std::ostream &out, const Point &p)
{
	out << p.toString();
	return out;
}

//Making useable for save and load
std::istream& operator>>(std::istream &in,  Point &p)
{
	std::string temp;
	std::getline(in, temp);
	//find delimiter
	size_t pos = temp.find(",");
	std::string beg, end;
	//create substrings
	if (pos != std::string::npos)
	{
		beg = temp.substr(0, pos);
		end = temp.substr(pos + 1, temp.length());
		//remove ",", " ", "(" from substring beg
		beg.erase(std::remove(beg.begin(), beg.end(), ','), beg.end());
		beg.erase(std::remove_if(beg.begin(), beg.end(), isspace), beg.end());
		beg.erase(std::remove(beg.begin(), beg.end(), '('), beg.end());

		//remove ")", " ", ","
		end.erase(std::remove_if(end.begin(), end.end(), isspace), beg.end());
		end.erase(std::remove(end.begin(), end.end(), ')'), beg.end());
		end.erase(std::remove(end.begin(), end.end(), ','));

		float x = float(std::stof(beg));
		float y = float(std::stof(end));
		p.set(x, y);
		return in;
	}
	else
	{
		//error while loading due to wrong type/delimiter
		p.set(0, 0);
		return in;
	}
}