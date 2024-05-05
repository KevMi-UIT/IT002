#pragma once
#include <iostream>
using namespace std;
class CTime
{
  private:
    int gio;
    int phut;
    int giay;

  private:
    int TinhSoGiay() const;

  public:
    friend class CTimeSpan;
    CTime(int gio = 0, int phut = 0, int giay = 0) : gio(gio), phut(phut), giay(giay)
    {
    }
    friend istream &operator>>(istream &, CTime &);
    friend ostream &operator<<(ostream &, CTime &);
    CTime operator-(int &);
    CTime operator+(int &);
    CTime operator++();
    CTime operator--();
    CTimeSpan TruCTS(const CTime &) const;
};