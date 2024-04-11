#include "CTimeSpan.h"
#include <iostream>
using namespace std;

void CTimeSpan::Nhap()
{
    cout << "Nhap so giay: ";
    cin >> this->length;
}

void CTimeSpan::Xuat() const
{
    cout << "Gia tri: " << this->length;
}

double CTimeSpan::getLength() const
{
    return this->length;
}

CTimeSpan CTimeSpan::Cong(const CTimeSpan &other) const
{
    return CTimeSpan(this->length + other.length);
}

CTimeSpan CTimeSpan::Tru(const CTimeSpan &other) const
{
    return CTimeSpan(this->length - other.length);
}

CTimeSpan CTimeSpan::Nhan(const CTimeSpan &other) const
{
    return CTimeSpan(this->length * other.length);
}

CTimeSpan CTimeSpan::Chia(const CTimeSpan &other) const
{
    return CTimeSpan(this->length / other.length);
}

bool CTimeSpan::Bang(const CTimeSpan &other) const
{
    return this->length == other.length;
}

bool CTimeSpan::Khac(const CTimeSpan &other) const
{
    return this->length != other.length;
}

bool CTimeSpan::LonHon(const CTimeSpan &other) const
{
    return this->length > other.length;
}

bool CTimeSpan::LonHonBang(const CTimeSpan &other) const
{
    return this->length >= other.length;
}

bool CTimeSpan::BeHon(const CTimeSpan &other) const
{
    return this->length < other.length;
}

bool CTimeSpan::BeHonBang(const CTimeSpan &other) const
{
    return this->length <= other.length;
}
