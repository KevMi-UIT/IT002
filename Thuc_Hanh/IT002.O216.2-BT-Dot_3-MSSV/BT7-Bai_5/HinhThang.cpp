#include "HinhThang.h"
#include <iostream>

using namespace std;

bool HinhThang::validate()
{
    this->valid = true;
    return true;
}

void HinhThang::Nhap()
{
    this->HinhHoc::Nhap();
    this->validate();
}

void HinhThang::Xuat() const
{
    if (this->valid)
        cout << "La hinh thang" << endl;
    else
        cout << "Khong phai la hinh thang" << endl;
    this->HinhHoc::Xuat();
}
