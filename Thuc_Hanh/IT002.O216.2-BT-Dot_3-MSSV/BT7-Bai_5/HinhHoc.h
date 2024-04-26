#pragma once
#include "Diem.h"
#include <iostream>

using namespace std;

class HinhHoc
{
  protected:
    Diem d1, d2, d3, d4;
    bool valid = false;

  public:
    HinhHoc()
    {
    }
    virtual bool validate() = 0;
    virtual void Nhap();
    virtual void Xuat() const;
    virtual ~HinhHoc() = default;
};
