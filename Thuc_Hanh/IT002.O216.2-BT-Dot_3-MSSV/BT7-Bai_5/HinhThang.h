#pragma once
#include "HinhHoc.h"

class HinhThang : public HinhHoc
{
  public:
    HinhThang() = default;
    bool validate();
    void Nhap() override;
    void Xuat() const override;
    ~HinhThang() = default;
};
