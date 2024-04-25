#pragma once
#include <string>
using namespace std;

class Nguoi
{
  protected:
    string Hoten;
    int NamSinh;

  public:
    Nguoi()
    {
        Hoten = "";
        NamSinh = 0;
    }
    Nguoi(string ht, int ns) : NamSinh(ns), Hoten(ht)
    {
    }
    void Nhap();
    virtual void Xuat() const;
};
