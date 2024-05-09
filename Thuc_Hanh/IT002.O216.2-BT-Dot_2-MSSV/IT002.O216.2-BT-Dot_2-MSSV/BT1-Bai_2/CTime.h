#pragma once
#include "CTimeSpan.h"
#include <iostream>

using namespace std;

class CTime
{
private:
	int gio;
	int phut;
	int giay;
	CTimeSpan timeSpan;
	int GetTotalSeconds() const;
	void Sync();

public:
	CTime(int _gio = 0, int _phut = 0, int _giay = 0);
	CTime operator=(const CTime&);
	friend istream& operator>>(istream&, CTime&);
	friend ostream& operator<<(ostream&, const CTime&);
	CTime operator-(const int&) const;
	CTime operator+(const int&) const;
	CTimeSpan operator-(const CTime&) const;
	CTime operator++();
	CTime operator--();
};