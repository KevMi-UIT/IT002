#include "NhanVien.h"
#include "NhanVienSX.h"
#include "NhanVienVP.h"
#include "QuanLyNhanVien.h"
#include <iostream>
#include <vector>
void QuanLyNhanVien::Nhap()
{
    cout << "Nhap so luong nhan vien van phong: ";
    cin >> this->SoluongNhanvienvp;
    NVVP = new NhanVienVP *[SoluongNhanvienvp];
    for (int i = 0; i < SoluongNhanvienvp; i++)
    {
        cout << "Nhap thong tin nhan vien van phong thu " << i + 1 << endl;
        NVVP[i] = new NhanVienVP;
        NVVP[i]->Nhap();
    }

    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> this->SoluongNhanviensx;
    NVSX = new NhanVienSX *[SoluongNhanviensx];
    for (int j = 0; j < SoluongNhanviensx; j++)
    {
        cout << "Nhap thong tin nhan vien san xuat thu " << j + 1 << endl;
        NVSX[j] = new NhanVienSX;
        NVSX[j]->Nhap();
    }
}

void QuanLyNhanVien::Xuat()
{
    cout << "Danh sach nhan vien van phong:\n";
    for (int i = 0; i < SoluongNhanvienvp; i++)
    {
        cout << "Thong tin nhan vien van phong thu " << i + 1 << endl;
        NVVP[i]->Xuat();
        cout << "Luong: " << NVVP[i]->Luong() << endl;
    }

    cout << "Danh sach nhan vien san xuat:\n";
    for (int j = 0; j < SoluongNhanviensx; j++)
    {
        cout << "Thong tin nhan vien san xuat thu " << j + 1 << endl;
        NVSX[j]->Xuat();
        cout << "Luong: " << NVSX[j]->Luong() << endl;
    }
}
