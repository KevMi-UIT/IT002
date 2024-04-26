#include "Diem.h"
#include "HinhChuNhat.h"
#include <iostream>

using namespace std;

bool HinhChuNhat::kiemTraCanhVuong(const Diem &d1, const Diem &d2, const Diem &d3)
{
    float v1_a = d1.getX() - d2.getX();
    float v1_b = d1.getY() - d2.getY();
    float v2_a = d2.getX() - d3.getX();
    float v2_b = d2.getY() - d3.getY();
    return v1_a * v2_a + v1_b * v2_b == 0;
}

bool HinhChuNhat::validate()
{
    if (this->HinhBinhHanh::validate() && this->kiemTraCanhVuong(this->d1, this->d2, this->d3))
    {
        this->valid = true;
        return true;
    }
    this->valid = false;
    return false;
}

void HinhChuNhat::Nhap()
{
    this->HinhHoc::Nhap();
    this->validate();
}

void HinhChuNhat::Xuat() const
{
    if (this->valid)
        cout << "La hinh chu nhat" << endl;
    else
        cout << "Khong phai la hinh chu nhat" << endl;
    this->HinhHoc::Xuat();
}
