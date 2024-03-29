#include "phanso.h"
#include <cmath>
#include <iostream>
using namespace std;

PhanSo::PhanSo()
{
    this->tu = 0;
    this->mau = 1;
}

PhanSo::~PhanSo()
{
}

void PhanSo::Nhap()
{
    do
    {
        cout << "Nhap tu so: ";
        cin >> this->tu;
        cout << "Nhap mau so: ";
        cin >> this->mau;
    } while (this->mau == 0);
}

void PhanSo::Xuat() const
{

    if (this->mau == 1)
        cout << this->tu;
    else if (this->mau == -1)
        cout << this->tu;
    else
        cout << this->tu << "/" << this->mau;
    cout << endl;
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
    return c;
}

PhanSo PhanSo ::operator*(PhanSo &b) const
{
    PhanSo c;
    c.tu = this->tu * b.tu;
    c.mau = this->mau * b.mau;
    return c;
}

PhanSo PhanSo::operator-(PhanSo &b) const
{
    PhanSo c;
    c.tu = this->tu * b.mau - this->mau * b.tu;
    c.mau = this->mau * b.mau;
    return c;
}

PhanSo PhanSo::operator/(PhanSo &b) const
{
    PhanSo c;
    c.tu = this->tu * b.mau;
    c.mau = this->mau * b.tu;
    return c;
}
