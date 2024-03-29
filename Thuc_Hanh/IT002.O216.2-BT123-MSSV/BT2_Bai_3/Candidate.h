#pragma once
#include <string>
using namespace std;

class Candidate
{
  private:
    string maSo;
    string hoTen;
    float diemToan;
    float diemVan;
    float diemAnh;
    float diemTong;

  public:
    Candidate();
    void Nhap();
    void Xuat() const;
    bool DiemHon15() const;

  private:
    void TinhDiemTong();
};
