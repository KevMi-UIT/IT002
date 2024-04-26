#pragma once
#include <iostream>
class CDate
{
  private:
    int ngay, thang, nam;

  public:
    CDate()
    {
        ngay = 0;
        thang = 0;
        nam = 0;
    };
    ~CDate(){};
    bool isLeap();
    bool isValid();
    void Nhap();
    void Xuat() const;
    CDate Cong(int) const;
    CDate Tru(int) const;
    CDate Them1ngay() const;
    CDate Bot1ngay() const;
    long KhoangCach(CDate &) const;
};
