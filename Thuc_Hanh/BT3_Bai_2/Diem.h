#pragma once
class Diem
{
  private:
    int x;
    int y;

  public:
    Diem();
    ~Diem();
    void nhap();
    void xuat();
    void tinhtien(int, int);
    void thuphong(int);
    void quay(int);
    friend class TamGiac;
};
