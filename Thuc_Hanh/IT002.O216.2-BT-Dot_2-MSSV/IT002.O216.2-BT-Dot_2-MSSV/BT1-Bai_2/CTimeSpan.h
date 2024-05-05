#pragma once
#include <iostream>
using namespace std;
class CTimeSpan
{
  private:
    long length;

  public:
    CTimeSpan(const long &_Length = 0) : length(_Length)
    {
    }
    friend class CTime;
    friend istream &operator>>(istream &, CTimeSpan &);
    friend ostream &operator<<(ostream &, const CTimeSpan &);
    long getLength() const;
    CTimeSpan operator+(const CTimeSpan &) const;
    CTimeSpan operator-(const CTimeSpan &) const;
    bool operator==(const CTimeSpan &) const;
    bool operator!=(const CTimeSpan &) const;
    bool operator>(const CTimeSpan &) const;
    bool operator>=(const CTimeSpan &) const;
    bool operator<(const CTimeSpan &) const;
    bool operator<=(const CTimeSpan &) const;
};
