#pragma once
#include "Nguoi.h"
class CongNhan : public Nguoi
{
    int Luong;

  public:
    CongNhan() : Nguoi("", 0){};
    void Nhap();
    void Xuat() const;
};
