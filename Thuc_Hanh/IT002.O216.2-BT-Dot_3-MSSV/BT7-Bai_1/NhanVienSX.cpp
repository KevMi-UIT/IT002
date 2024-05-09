#include "NhanVienSX.h"
void NhanVienSX::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap luong co ban: ";
    cin >> this->Luongcoban;
    cout << "Nhap so gio lam: ";
    cin >> this->Sogiolam;
}
void NhanVienSX::Xuat()
{
    NhanVien::Xuat();
    cout << "Luong co ban la: ";
    cout << this->Luongcoban;
    cout << "So gio lam la: ";
    cout << this->Sogiolam;
}
double NhanVienSX::getLuongcoban() const
{
    return this->Luongcoban;
}
double NhanVienSX::getSogiolam() const
{
    return this->Sogiolam;
}
double NhanVienSX::Luong()
{
    return getLuongcoban() + getSogiolam() * 5000;
}
