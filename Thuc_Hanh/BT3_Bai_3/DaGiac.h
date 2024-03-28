#pragma once
#include "Diem.h"
#include <vector>
using namespace std;

class DaGiac
{
  public:
    DaGiac();
    ~DaGiac();
    void Nhap();
    void Xuat() const;
    DaGiac TinhTien(float &, float &);
    DaGiac Quay(float &);
    DaGiac ThuPhong(float &);

  private:
    int soDiem;
    vector<Diem> Point;
};
