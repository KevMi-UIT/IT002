#pragma once
#include "NhanVien.h"
#include <iostream>
using namespace std;
class NhanVienVP : public NhanVien
{
  private:
    int Songaylam;

  public:
    void Nhap();
    void Xuat();
    double getSongaylam();
    double Luong();
};
