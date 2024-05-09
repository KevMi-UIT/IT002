#pragma once
#include <iostream>
#include <string>
using namespace std;
class NhanVien
{
  private:
    char HoTen[50];
    int Ngay;
    int Thang;
    int Nam;
    int SoNgayLam;

  public:
    void Nhap();
    void Xuat();
    double Luong();
};
