#include "CTime.h"
#include "CTimeSpan.h"
#include <cmath>
#include <iostream>

using namespace std;

CTime::CTime(int _gio, int _phut, int _giay) : gio(_gio), phut(_phut), giay(_giay)
{
	this->Sync();
}

CTime CTime::operator=(const CTime& other)
{
	this->gio = other.gio;
	this->phut = other.phut;
	this->giay = other.giay;
	this->timeSpan = other.timeSpan;
	return *this;
}

int CTime::GetTotalSeconds() const
{
	return (this->gio * 3600 + this->phut * 60 + this->giay);
}

void CTime::Sync()
{
	int tongGiay = this->timeSpan.getLength();
	this->gio = tongGiay / 3600;
	this->phut = (tongGiay % 3600) / 60;
	this->giay = tongGiay % 60;
}

istream& operator>>(istream& is, CTime& ctime)
{
	cout << "Nhap gio: ";
	is >> ctime.gio;
	cout << "Nhap phut: ";
	is >> ctime.phut;
	cout << "Nhap giay: ";
	is >> ctime.giay;
	ctime.timeSpan.setLength(ctime.GetTotalSeconds());
	ctime.Sync();
	return is;
}

ostream& operator<<(ostream& os, const CTime& ctime)
{
	os << ctime.gio << " gio " << ctime.phut << " phut " << ctime.giay << " giay";
	return os;
}

CTime CTime::operator+(const int& _giay) const
{
	CTime result = *this;
	result.timeSpan += _giay;
	result.Sync();
	return result;
}

CTime CTime::operator-(const int& _giay) const
{
	CTime result = *this;
	result.timeSpan -= _giay;
	result.Sync();
	return result;
}

CTimeSpan CTime::operator-(const CTime& ctime) const
{
	return CTimeSpan(abs(this->GetTotalSeconds() - ctime.GetTotalSeconds()));
}

CTime CTime::operator++()
{
	return *this + 1;
}

CTime CTime::operator--()
{
	return *this - 1;
}
