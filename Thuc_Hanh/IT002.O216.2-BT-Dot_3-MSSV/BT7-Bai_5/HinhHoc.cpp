#include "HinhHoc.h"
#include <iostream>

using namespace std;

void HinhHoc::Nhap()
{
    cout << "Nhap toa do cac diem:" << endl;
    cout << "Nhap diem d1:" << endl;
    cin >> this->d1;
    cout << "Nhap diem d2:" << endl;
    cin >> this->d2;
    cout << "Nhap diem d3:" << endl;
    cin >> this->d3;
    cout << "Nhap diem d4:" << endl;
    cin >> this->d4;
}

void HinhHoc::Xuat() const
{
    cout << "Toa do cac diem:" << endl;
    cout << "Diem d1: " << this->d1 << endl;
    cout << "Diem d2: " << this->d2 << endl;
    cout << "Diem d3: " << this->d3 << endl;
    cout << "Diem d4: " << this->d4 << endl;
}
