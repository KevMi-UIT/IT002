#include "NhanVien.h"
#include "NhanVienVP.h"
#include <iostream>
using namespace std;
void NhanVienVP::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap so ngay lam: ";
    cin >> this->Songaylam;
}
void NhanVienVP::Xuat()
{
    cout << "So ngay lam: ";
    NhanVien::Xuat();
    cout << this->Songaylam << endl;
}
double NhanVienVP::getSongaylam()
{
    return this->Songaylam;
}
double NhanVienVP::Luong()
{
    return getSongaylam() * 100000;
}
