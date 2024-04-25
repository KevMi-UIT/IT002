#include "HinhHoc.h"
#include <iostream>

using namespace std;

bool HinhHoc::kiemTraCanhVuong(const Diem &d1, const Diem &d2, const Diem &d3)
{
    float v1_a = d1.getX() - d2.getX();
    float v1_b = d1.getY() - d2.getY();
    float v2_a = d2.getX() - d3.getX();
    float v2_b = d2.getY() - d3.getY();
    return v1_a * v2_a + v1_b * v2_b == 0;
}

void HinhHoc::setType()
{
    float l1 = this->d1.tinhKhoangCach(this->d2);
    float l2 = this->d2.tinhKhoangCach(this->d3);
    float l3 = this->d3.tinhKhoangCach(this->d4);
    float l4 = this->d4.tinhKhoangCach(this->d1);
    if (l1 == l3)
        this->type = 2;
    if (this->type == 2 and this->kiemTraCanhVuong(d1, d2, d3))
        this->type = 3;
    if (this->type == 3 and l1 == l2)
        this->type = 4;
}

istream &operator>>(istream &is, HinhHoc &s)
{
    cout << "Nhap toa do cac diem:" << endl;
    cout << "Nhap diem d1:" << endl;
    is >> s.d1;
    cout << "Nhap diem d2:" << endl;
    is >> s.d2;
    cout << "Nhap diem d3:" << endl;
    is >> s.d3;
    cout << "Nhap diem d4:" << endl;
    is >> s.d4;
    s.setType();
    return is;
}

ostream &operator<<(ostream &os, const HinhHoc &s)
{
    switch (s.type)
    {
    case 1: {
        os << "La hinh thang" << endl;
        break;
    }
    case 2: {
        os << "La hinh binh hanh" << endl;
        break;
    }
    case 3: {
        os << "La hinh chu nhat" << endl;
        break;
    }
    case 4: {
        os << "La hinh vuong" << endl;
        break;
    }
    default:
        os << "Khong xac dinh" << endl;
    }
    os << "Diem d1: " << s.d1 << endl;
    os << "Diem d2: " << s.d2 << endl;
    os << "Diem d3: " << s.d3 << endl;
    os << "Diem d4: " << s.d4 << endl;
    return os;
}
