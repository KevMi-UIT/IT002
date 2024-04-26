#include "Diem.h"
#include "HinhBinhHanh.h"

#include <iostream>

using namespace std;

bool HinhBinhHanh::validate()
{
    if (Diem::tinhKhoangCach(this->d1, this->d2) == Diem::tinhKhoangCach(this->d3, this->d4))
    {
        this->valid = true;
        return true;
    }
    this->valid = false;
    return false;
}

void HinhBinhHanh::Nhap()
{
    this->HinhHoc::Nhap();
    this->validate();
}

void HinhBinhHanh::Xuat() const
{
    if (this->valid)
        cout << "La hinh binh hanh" << endl;
    else
        cout << "Khong phai la hinh binh hanh" << endl;
    this->HinhHoc::Xuat();
}
