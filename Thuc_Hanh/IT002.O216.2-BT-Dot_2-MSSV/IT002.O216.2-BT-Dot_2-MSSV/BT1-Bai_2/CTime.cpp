#include "CTime.h"
#include <iostream>
using namespace std;
int CTime::TinhSoGiay() const
{
    return (this->gio * 3600 + this->phut * 60 + this->giay);
}
istream &operator>>(istream &is, CTime &ctime)
{
    cout << "Nhap gio: ";
    is >> ctime.gio;
    cout << "Nhap phut: ";
    is >> ctime.phut;
    cout << "Nhap giay: ";
    is >> ctime.giay;
    return is;
}
ostream &operator<<(ostream &os, CTime &ctime)
{

    if (ctime.giay >= 60)
    {
        ctime.giay -= 60;
        ctime.phut++;
    }
    if (ctime.phut >= 60)
    {
        ctime.phut -= 60;
        ctime.gio++;
    }
    os << ctime.gio << " gio " << ctime.phut << " phut " << ctime.giay << " giay";
    return os;
}
CTime CTime::operator+(int &sogiay)
{
    CTime result;
    result.gio = this->gio;
    result.phut = this->phut;
    result.giay = this->giay;
    result.giay = this->giay + sogiay;
    return result;
}
CTime CTime::operator-(int &soGiay)
{
    CTime result;
    result.gio = this->gio;
    result.phut = this->phut;
    result.giay = this->giay;
    result.giay = result.giay - soGiay;
    while (result.giay <= 0)
    {
        result.giay = 60 + result.giay;
        result.phut--;
    }
    while (result.phut <= 0)
    {
        result.phut = 60 + result.phut;
        result.gio--;
    }
    if (result.gio <= 0)
        result.gio = 0;
    return result;
}

// CTime
/* CTime CTime::TruCTS(const CTime &other) const
{
    CTime Time;
    int tongGiay = this->gio * 3600 + this->phut * 60 + this->giay - (other.gio * 3600 + other.phut * 60 +
other.giay); Time.gio = tongGiay / 3600; Time.phut = (tongGiay % 3600) / 60; Time.giay = (tongGiay % 3600) % 60;
    return Time;
}*/
CTime CTime::operator++()
{
    CTime result;
    result.gio = this->gio;
    result.phut = this->phut;
    result.giay = this->giay;
    result.giay++;
    return result;
}

CTime CTime::operator--()
{
    CTime result;
    result.gio = this->gio;
    result.phut = this->phut;
    result.giay = this->giay;
    result.giay--;
    if (result.giay == 0)
    {
        result.giay = 59;
        result.phut--;
    }
    if (result.phut == 0)
    {
        result.phut = 59;
        result.gio--;
    }
    if (result.gio <= 0)
        result.gio = 0;
    return result;
}
