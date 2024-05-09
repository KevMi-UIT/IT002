<<<<<<< HEAD
#pragma once
#include <iostream>
using namespace std;
class CTimeSpan
{
private:
	int length;

public:
	CTimeSpan(const int& _Length = 0) : length(_Length)
	{}
	friend class CTime;
	friend istream& operator>>(istream&, CTimeSpan&);
	friend ostream& operator<<(ostream&, const CTimeSpan&);
	int getLength() const;
	void setLength(const int&);
	CTimeSpan operator+(const CTimeSpan&) const;
	CTimeSpan operator-(const CTimeSpan&) const;
	void operator+=(const CTimeSpan& other);
	void operator-=(const CTimeSpan& other);
};
=======
#pragma once
#include <iostream>
using namespace std;
class CTimeSpan
{
private:
	int length;

public:
	CTimeSpan(const int& _Length = 0) : length(_Length)
	{}
	friend class CTime;
	friend istream& operator>>(istream&, CTimeSpan&);
	friend ostream& operator<<(ostream&, const CTimeSpan&);
	int getLength() const;
	void setLength(const int&);
	CTimeSpan operator+(const CTimeSpan&) const;
	CTimeSpan operator-(const CTimeSpan&) const;
	void operator+=(const CTimeSpan& other);
	void operator-=(const CTimeSpan& other);
};
>>>>>>> c64f07068610dc96a85f0a5df4a532b3e07d6e85
