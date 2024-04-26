#include "Diem.h"
#include "HinhVuong.h"
#include <iostream>

using namespace std;

bool HinhVuong::kiemTraCanhBang(const Diem &d1, const Diem &d2, const Diem &d3, const Diem &d4)
{
    float d1d2 = Diem::tinhKhoangCach(d1, d2);
    float d2d3 = Diem::tinhKhoangCach(d2, d3);
    float d3d4 = Diem::tinhKhoangCach(d3, d4);
    float d4d1 = Diem::tinhKhoangCach(d4, d1);
    return d1d2 == d2d3 && d2d3 == d3d4 && d3d4 == d4d1;
}

bool HinhVuong::validate()
{
    if (this->HinhChuNhat::validate() && this->kiemTraCanhBang(this->d1, this->d2, this->d3, this->d4))
    {
        this->valid = true;
        return true;
    }
    this->valid = false;
    return false;
}

void HinhVuong::Nhap()
{
    this->HinhHoc::Nhap();
    this->validate();
}

void HinhVuong::Xuat() const
{
    if (this->valid)
        cout << "La hinh vuong" << endl;
    else
        cout << "Khong phai la hinh vuong" << endl;
    this->HinhHoc::Xuat();
}
