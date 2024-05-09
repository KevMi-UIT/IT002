#pragma once
#include "NhanVienSX.h"
#include "NhanVienVP.h"
#include <iostream>
#include <vector>
using namespace std;
class QuanLyNhanVien
{
  private:
    int SoluongNhanvienvp;
    NhanVienVP **NVVP;
    int SoluongNhanviensx;
    NhanVienSX **NVSX;

  public:
    void Nhap();
    void Xuat();
};
