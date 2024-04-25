#pragma once
#include "Nguoi.h"
class NgheSi : public Nguoi
{
    long long CatXe;
    int TuoiNghe;

  public:
    NgheSi() : Nguoi("", 0){};
    NgheSi(string ht, int nam, int salary, int exp) : Nguoi(ht, nam)
    {
        CatXe = salary;
        TuoiNghe = exp;
    }
    void Nhap();
    void Xuat() const;
};
