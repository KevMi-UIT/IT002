#pragma once
#include "Nguoi.h"
class HocSinh : public Nguoi
{
    int MaHS;
    string Lop;

  public:
    HocSinh() : Nguoi("", 0){};
    HocSinh(string ht, int ns, int mHS) : Nguoi(ht, ns)
    {
        MaHS = mHS;
    }
    void Nhap();
    void Xuat() const;
};
