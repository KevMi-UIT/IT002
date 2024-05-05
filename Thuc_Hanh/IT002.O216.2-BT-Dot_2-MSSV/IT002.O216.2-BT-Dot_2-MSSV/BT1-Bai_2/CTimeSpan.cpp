#include "CTimeSpan.h"
#include <iostream>

using namespace std;

istream &operator>>(istream &is, CTimeSpan &time)
{
    cout << "Nhap so giay: ";
    is >> time.length;
    return is;
}

ostream &operator<<(ostream &os, const CTimeSpan &time)
{
    os << time.length;
    return os;
}

long CTimeSpan::getLength() const
{
    return this->length;
}

CTimeSpan CTimeSpan::operator+(const CTimeSpan &other) const
{
    return CTimeSpan(this->length + other.length);
}

CTimeSpan CTimeSpan::operator-(const CTimeSpan &other) const
{
    return CTimeSpan(this->length - other.length);
}

bool CTimeSpan::operator==(const CTimeSpan &other) const
{
    return this->length == other.length;
}

bool CTimeSpan::operator!=(const CTimeSpan &other) const
{
    return this->length != other.length;
}

bool CTimeSpan::operator>(const CTimeSpan &other) const
{
    return this->length > other.length;
}

bool CTimeSpan::operator>=(const CTimeSpan &other) const
{
    return this->length >= other.length;
}

bool CTimeSpan::operator<(const CTimeSpan &other) const
{
    return this->length < other.length;
}

bool CTimeSpan::operator<=(const CTimeSpan &other) const
{
    return this->length <= other.length;
}
