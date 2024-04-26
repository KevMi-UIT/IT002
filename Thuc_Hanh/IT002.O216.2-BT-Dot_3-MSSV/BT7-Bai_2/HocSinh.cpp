#include "HocSinh.h"
#include "Nguoi.h"
#include <iostream>
using namespace std;

void HocSinh::Nhap()
{
    Nguoi::Nhap();
    cout << "Nhap lop: ";
    cin >> this->Lop;
    cout << "Nhap ma hoc sinh: ";
    cin >> this->MaHS;
}

void HocSinh::Xuat() const
{
    Nguoi::Xuat();
    cout << "Nghe nghiep: Hoc Sinh" << endl;
    cout << "Hoc sinh lop " << this->Lop << endl;
    cout << "Ma so hoc sinh: " << this->MaHS;
}
