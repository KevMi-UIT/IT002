#include "NhanVien.h"
#include <iostream>
#include <vector>
using namespace std;
void NhanVien::Nhap()
{
    cout << "Nhap ho ten: ";
    cin >> this->HoTen;
    cout << "Nhap ngay thang nam sinh" << endl;
    cin >> this->Ngay >> this->Thang >> this->Nam;
}
void NhanVien::Xuat() const
{
    cout << this->HoTen << endl;
    cout << this->Ngay << this->Thang << this->Nam << endl;
}
double NhanVien::Luong()
{
    return 0;
}
