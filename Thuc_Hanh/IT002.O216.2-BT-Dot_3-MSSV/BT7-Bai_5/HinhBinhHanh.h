#pragma once
#include "HinhThang.h"

class HinhBinhHanh : public HinhThang
{
  public:
    HinhBinhHanh() = default;
    bool validate();
    void Nhap() override;
    void Xuat() const override;
    ~HinhBinhHanh() = default;
};
