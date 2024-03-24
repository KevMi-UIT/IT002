#pragma once
class PhanSo
{
  public:
    PhanSo();
    ~PhanSo();
    void Nhap();
    void Xuat() const;
    PhanSo Rutgon();
    PhanSo operator+(PhanSo &) const;
    PhanSo operator-(PhanSo &) const;
    PhanSo operator*(PhanSo &) const;
    PhanSo operator/(PhanSo &) const;

  private:
    int tu;
    int mau;
};
