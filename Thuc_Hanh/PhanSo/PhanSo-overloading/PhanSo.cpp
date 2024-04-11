#include "phanso.h"
#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

PhanSo::PhanSo()
{
    this->tu = 0;
    this->mau = 1;
}

PhanSo::~PhanSo(){};

istream &operator>>(istream &is, PhanSo &P)
{
    do
    {
        cout << "Nhap tu so: ";
        is >> P.tu;
        cout << "Nhap mau so: ";
        is >> P.mau;
    } while (P.tu == 0);
    P.Rutgon();
    return is;
}

/* istream &operator>>(istream &is, PhanSo &p)
{
    is >> p.tu >> p.mau;
    while (!p.mau)
    {
        cout << " Nhap lai: ";
        is >> p.mau;
    }
    return is;
}
*/

ostream &operator<<(ostream &os, PhanSo P)
{
    if (P.tu == 1)
        os << P.tu;
    else if (P.mau == -1)
        os << P.mau;
    else
        os << P.tu << "/" << P.mau;
    return os;
}

int maxUoc(int a, int b)
{
    int m = abs(a);
    int n = abs(b);
    while (m * n != 0)
    {
        if (m > n)
            m -= n;
        else
            n -= m;
    }
    return m + n;
}

PhanSo PhanSo::Rutgon()
{
    PhanSo res;
    int i = maxUoc(this->mau, this->tu);
    if (this->mau < 0)
    {
        res.tu = this->tu / (-i);
        res.mau = this->mau / (-i);
    }
    else
    {
        res.tu = this->tu / i;
        res.mau = this->mau / i;
    }
    return res;
}

PhanSo PhanSo::operator+(PhanSo &b) const
{
    PhanSo c;
    c.tu = this->tu * b.mau + this->mau * b.tu;
    c.mau = this->mau * b.mau;
    return c.Rutgon();
}

PhanSo PhanSo ::operator*(PhanSo &b) const
{
    PhanSo c;
    c.tu = this->tu * b.tu;
    c.mau = this->mau * b.mau;
    return c.Rutgon();
}

PhanSo PhanSo::operator-(PhanSo &b) const
{
    PhanSo c;
    c.tu = this->tu * b.mau - this->mau * b.tu;
    c.mau = this->mau * b.mau;
    return c.Rutgon();
}

PhanSo PhanSo::operator/(PhanSo &b) const
{
    PhanSo c;
    c.tu = this->tu * b.mau;
    c.mau = this->mau * b.tu;
    return c.Rutgon();
}
