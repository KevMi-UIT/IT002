#pragma once
#include <iostream>
using namespace std;
class CTime
{
  private:
    int gio;
    int phut;
    int giay;

  private:
    int TinhSoGiay() const;

  public:
    CTime(int gio = 0, int phut = 0, int giay = 0) : gio(gio), phut(phut), giay(giay)
    {
    }
    void Nhap();
    void Xuat() const;
    CTime ThemMotGiay() const;
    CTime BotMotGiay() const;
    CTime Cong(int) const;
    CTime Tru(int) const;
    CTime TruCTS(const CTime &) const;
};