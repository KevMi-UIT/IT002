#include "CongNhan.h"
#include "Nguoi.h"
#include <iostream>
using namespace std;

void CongNhan::Nhap()
{
    Nguoi::Nhap();
    cout << "Nhap luong: ";
    cin >> this->Luong;
}

void CongNhan::Xuat() const
{
    Nguoi::Xuat();
    cout << "Nghe nghiep: Cong Nhan" << endl;
    cout << "Luong: " << this->Luong << " dong";
}
