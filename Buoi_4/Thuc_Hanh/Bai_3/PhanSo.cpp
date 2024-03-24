#include "PhanSo.h"
#include <iostream>
using namespace std;
void PhanSo::Nhap()
{
    do
    {
        cout << "Nhap tu: ";
        cin >> tu;
        cout << "Nhap mau: ";
        cin >> mau;
    } while (mau == 0);
}
void PhanSo::Xuat()
{
    cout << "(" << tu << " / " << mau << ")";
}
