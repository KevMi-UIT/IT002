#pragma once
#include "Nguoi.h"
class SinhVien : public Nguoi
{
    int MSSV;

  public:
    SinhVien() : Nguoi("", 0)
    {
    }
    SinhVien(string ht, int ns, int mssv) : Nguoi(ht, ns)
    {
        MSSV = mssv;
    }
    void Nhap();
    void Xuat() const;
};
