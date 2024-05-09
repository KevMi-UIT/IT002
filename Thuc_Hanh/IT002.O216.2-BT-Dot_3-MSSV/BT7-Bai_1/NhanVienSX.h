#pragma once
#include "NhanVien.h"
#include <iostream>

using namespace std;
class NhanVienSX : public NhanVien
{
  private:
    int Luongcoban;
    int Sogiolam;

  public:
    void Nhap();
    void Xuat();
    double getLuongcoban() const;
    double getSogiolam() const;
    double Luong();
};
