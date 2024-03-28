#include "HocSinh.h"
#include <iostream>
#include <string>

using namespace std;

HocSinh::HocSinh() : hoTen{""}, diemToan(0), diemVan(0), diemTrungBinh(0){};

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
