#pragma once
#include "Diem.h"
#include "HinhChuNhat.h"

class HinhVuong : public HinhChuNhat
{
  public:
    HinhVuong() = default;
    static bool kiemTraCanhBang(const Diem &, const Diem &, const Diem &, const Diem &);
    bool validate();
    void Nhap() override;
    void Xuat() const override;
    ~HinhVuong() = default;
};
