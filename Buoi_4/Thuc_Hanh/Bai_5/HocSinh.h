#pragma once
#include <string>

using namespace std;

class HocSinh
{
  private:
    string hoTen;
    float diemToan;
    float diemVan;
    float diemTrungBinh;

  public:
    HocSinh();
    void Nhap();
    void Xuat() const;

  private:
    void TinhDiemTrungBinh();
};