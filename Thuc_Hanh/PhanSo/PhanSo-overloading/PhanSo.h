#pragma once
#include <iostream>
using namespace std;
class PhanSo
{
  public:
    PhanSo();
    ~PhanSo();

    PhanSo Rutgon();
    PhanSo operator+(PhanSo &) const;
    PhanSo operator-(PhanSo &) const;
    PhanSo operator*(PhanSo &) const;
    PhanSo operator/(PhanSo &) const;
    friend ostream &operator<<(ostream &os, PhanSo P);
    friend istream &operator>>(istream &is, PhanSo &P);

  private:
    int tu;
    int mau;
};
