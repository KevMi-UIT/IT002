#include "CDate.h"
#include <iostream>
using namespace std;

int day_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day_of_month_leapYear[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool CDate::isLeap()
{
    return (nam % 4 == 0) && (nam % 100 != 0 || nam % 400 == 0);
}

bool is_Leap(int nam)
{
    return (nam % 4 == 0) && (nam % 100 != 0 || nam % 400 == 0);
}

bool CDate::isValid()
{
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: {
        if (ngay <= 0 || ngay > 31)
            return 0;
        break;
    }

    case 4:
    case 6:
    case 9:
    case 11: {
        if (ngay <= 0 || ngay > 30)
            return 0;
        break;
    }

    case 2: {
        if (isLeap())
        {
            if (ngay <= 0 || ngay > 29)
                return 0;
            break;
        }
        else
        {
            if (ngay <= 0 || ngay > 28)
                return 0;
            break;
        }
    }
    default: {
        return 0;
        break;
    }
    }
    return 1;
}

void CDate::Nhap()
{
    do
    {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    } while (isValid() == 0);
}

void CDate::Xuat() const
{
    cout << "Ngay " << ngay << " thang " << thang << " nam " << nam << endl;
}
CDate CDate::Cong(int SoNgay) const
{
    CDate Date;
    Date.ngay = this->ngay;
    Date.thang = this->thang;
    Date.nam = this->nam;
    int tempDate = Date.ngay + SoNgay;
    do
    {
        if (!Date.isLeap())
            if (tempDate > day_of_month[Date.thang])
            {
                tempDate -= day_of_month[Date.thang];
                Date.thang++;
                if (Date.thang == 13)
                {
                    Date.nam++;
                    Date.thang = 1;
                }
            }
            else
            {
                Date.ngay = tempDate;
                tempDate = 0;
            }
        else
        {
            if (tempDate > day_of_month_leapYear[Date.thang])
            {
                tempDate -= day_of_month_leapYear[Date.thang];
                Date.thang++;
                if (Date.thang == 13)
                {
                    Date.nam++;
                    Date.thang = 1;
                }
            }
            else
            {
                Date.ngay = tempDate;
                tempDate = 0;
            }
        }
    } while (tempDate != 0);
    return Date;
}
CDate CDate::Tru(int SoNgay) const
{
    CDate Date;
    Date.ngay = this->ngay;
    Date.thang = this->thang;
    Date.nam = this->nam;
    int tempDate = Date.ngay - SoNgay;
    do
    {
        if (!Date.isLeap())
            if (tempDate > 0)
            {
                Date.ngay = tempDate;
                tempDate = 0;
            }
            else
            {
                Date.thang--;
                if (Date.thang == 0)
                {
                    Date.thang = 12;
                    Date.nam--;
                }
                tempDate = day_of_month[Date.thang] + tempDate;
            }
        else
        {
            if (tempDate > 0)
            {
                Date.ngay = tempDate;
                tempDate = 0;
            }
            else
            {
                Date.thang--;
                if (Date.thang == 0)
                {
                    Date.thang = 12;
                    Date.nam--;
                }
                tempDate = day_of_month_leapYear[Date.thang] + tempDate;
            }
        }
    } while (tempDate != 0);
    return Date;
}
CDate CDate::Them1ngay() const
{
    return this->Cong(1);
}
CDate CDate::Bot1ngay() const
{
    return this->Tru(1);
}
long CDate::KhoangCach(CDate &other) const
{
    //     2/2/2012 - 2/4/2024
    //     0/2/12
    long days_1 = 0;
    long days_2 = 0;
    for (int i = 1; i < this->nam; i++)
    {
        if (is_Leap(i))
            days_1 += 366;
        else
            days_1 += 365;
    }

    for (int i = 1; i < other.nam; i++)
    {
        if (is_Leap(i))
            days_2 += 366;
        else
            days_2 += 365;
    }

    if (is_Leap(this->nam))
    {
        for (int i = 1; i < this->thang; i++)
            days_1 += day_of_month_leapYear[i];
        for (int i = 1; i <= this->ngay; i++)
            days_1++;
    }
    else
    {
        for (int i = 1; i < this->thang; i++)
            days_1 += day_of_month[i];
        for (int i = 1; i <= this->ngay; i++)
            days_1++;
    }

    if (is_Leap(other.nam))
    {
        for (int i = 1; i < other.thang; i++)
            days_2 += day_of_month_leapYear[i];
        for (int i = 1; i <= other.ngay; i++)
            days_2++;
    }
    else
    {
        for (int i = 1; i < other.thang; i++)
            days_2 += day_of_month[i];
        for (int i = 1; i <= other.ngay; i++)
            days_2++;
    }
    return abs(days_2 - days_1);
}
