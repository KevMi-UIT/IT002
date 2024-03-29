#include "PhanSo.h"
#include <cmath>
#include <iostream>
using namespace std;

PhanSo::PhanSo()
{
    this->tu = 1;
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
        cout << "Phan so da rut gon: " << this->tu;
    else
        cout << "Phan so da rut gon: " << this->tu << "/" << this->mau;
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

void PhanSo::Rutgon()
{
    int i = maxUoc(this->mau, this->tu);
    if (this->mau < 0)
    {
        this->mau /= (-i);
        this->tu /= (-i);
    }
    else
    {
        this->mau /= i;
        this->tu /= i;
    }
}
