#include "PhanSo.h"
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
        cout << " Nhap tu: ";
        cin >> tu;
        cout << "Nhap mau: ";
        cin >> mau;
    } while (mau == 0);
}
void PhanSo::Xuat() const
{
    cout << "(" << tu << " / " << mau << ") ";
}
double PhanSo::getTu() const
{
    return tu;
}
double PhanSo::getMau() const
{
    return mau;
}
void PhanSo::Giatri(double t1, double t2, double m1, double m2)
{
    tu = t1 * m2 - t2 * m1;
}
void PhanSo::Max(PhanSo &ps1, PhanSo &ps2, PhanSo &ps3)
{
    ps3.Giatri(ps1.getTu(), ps2.getTu(), ps1.getMau(), ps2.getMau());
}
