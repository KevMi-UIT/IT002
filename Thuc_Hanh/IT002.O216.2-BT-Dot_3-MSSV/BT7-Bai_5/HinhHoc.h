#pragma once
#include "Diem.h"
#include <iostream>

using namespace std;

// Hinh thang: 1
// Hinh binh hanh: 2
// Hinh chu nhat: 3
// Hinh vuong: 4

class HinhHoc
{
  private:
    int type = 1;
    Diem d1, d2, d3, d4;
    void setType();

  public:
    HinhHoc()
    {
    }
    static bool kiemTraCanhVuong(const Diem &, const Diem &, const Diem &);
    friend istream &operator>>(istream &, HinhHoc &);
    friend ostream &operator<<(ostream &, const HinhHoc &);
    ~HinhHoc()
    {
    }
};
