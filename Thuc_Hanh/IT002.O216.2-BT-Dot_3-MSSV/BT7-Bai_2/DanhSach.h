#pragma once
#include "Nguoi.h"
#include <vector>

class DanhSach
{
  private:
    int soLuong;
    vector<Nguoi *> list;

  public:
    void Nhap();
    void Xuat() const;
};
