#pragma once
#include "NgheSi.h"
class CaSi : public NgheSi
{
  public:
    CaSi() : NgheSi("", 0, 0, 0){};
    void Nhap();
    void Xuat() const;
};
