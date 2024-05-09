#include "CTimeSpan.h"
#include <iostream>

using namespace std;

istream& operator>>(istream& is, CTimeSpan& time)
{
	cout << "Nhap so giay: ";
	is >> time.length;
	return is;
}

ostream& operator<<(ostream& os, const CTimeSpan& time)
{
	os << time.length;
	return os;
}

int CTimeSpan::getLength() const
{
	return this->length;
}

void CTimeSpan::setLength(const int& _Length)
{
	this->length = _Length;
}

CTimeSpan CTimeSpan::operator+(const CTimeSpan& other) const
{
	return CTimeSpan(this->length + other.length);
}

CTimeSpan CTimeSpan::operator-(const CTimeSpan& other) const
{
	return CTimeSpan(this->length - other.length);
}

void CTimeSpan::operator+=(const CTimeSpan& other)
{
	this->length += other.length;
}

void CTimeSpan::operator-=(const CTimeSpan& other)
{
	this->length -= other.length;
}

