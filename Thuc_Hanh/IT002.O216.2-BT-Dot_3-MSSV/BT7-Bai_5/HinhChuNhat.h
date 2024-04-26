#pragma once
#include "Diem.h"
#include "HinhBinhHanh.h"

class HinhChuNhat : public HinhBinhHanh
{
  public:
    HinhChuNhat() = default;
    static bool kiemTraCanhVuong(const Diem &, const Diem &, const Diem &);
    bool validate();
    void Nhap() override;
    void Xuat() const override;
    ~HinhChuNhat() = default;
};
