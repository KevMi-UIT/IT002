#include "Candidate.h"
#include <iostream>
#include <string>

using namespace std;

Candidate::Candidate() : maSo(""), hoTen(""), diemToan(0), diemVan(0), diemAnh(0), diemTong(0){};

void Candidate::Nhap()
{
    cout << "Nhap ma so sinh vien: ";
    cin.ignore();
    getline(cin, this->maSo);
    cout << "Nhap ho ten sinh vien: ";
    getline(cin, this->hoTen);
    cout << "Nhap diem toan: ";
    cin >> this->diemToan;
    cout << "Nhap diem van: ";
    cin >> this->diemVan;
    cout << "Nhap diem anh: ";
    cin >> this->diemAnh;
    this->TinhDiemTong();
}

bool Candidate::DiemHon15() const
{
    return this->diemTong > 15;
}

void Candidate::Xuat() const
{
    cout << "Hoc sinh: " << this->hoTen << " - Diem tong: " << this->diemTong << endl;
}

void Candidate::TinhDiemTong()
{
    this->diemTong = this->diemToan + this->diemVan + this->diemAnh;
}
