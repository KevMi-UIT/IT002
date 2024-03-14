#include "HocSinh.h"
#include <string>
#include <iostream>

using namespace std;

void HocSinh::Nhap()
{
    cout << "Nhap ho ten sinh vien: ";
    getline(cin, this->hoTen);
    cout << "Nhap diem toan: ";
    cin >> this->diemToan;
    cout << "Nhap diem van: ";
    cin >> this->diemVan;
    this->TinhDiemTrungBinh();
}

void HocSinh::Xuat() const
{
    cout << "Hoc sinh: " << this->hoTen << endl;
    cout << "Diem trung binh: " << this->diemTrungBinh << endl;
}

void HocSinh::TinhDiemTrungBinh()
{
    this->diemTrungBinh = (this->diemToan + this->diemVan) / 2;
}
