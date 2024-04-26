#include "CTime.h"
#include <iostream>
using namespace std;
int CTime::TinhSoGiay() const
{
    return (this->gio * 3600 + this->phut * 60 + this->giay);
}
void CTime::Nhap()
{
    cout << "Nhap gio: ";
    cin >> this->gio;
    cout << "Nhap phut: ";
    cin >> this->phut;
    cout << "Nhap giay: ";
    cin >> this->giay;
}
void CTime::Xuat() const
{
    int giay = this->giay;
    int phut = this->phut;
    int gio = this->gio;

    if (giay >= 60)
    {
        giay -= 60;
        phut++;
    }
    if (phut >= 60)
    {
        phut -= 60;
        gio++;
    }
    cout << gio << " gio " << phut << " phut " << giay << " giay";
}

CTime CTime::Cong(int sogiay) const
{
    CTime Time;
    Time.gio = this->gio;
    Time.phut = this->phut;
    Time.giay = this->giay;
    Time.giay = Time.giay + sogiay;
    return Time;
}
CTime CTime::Tru(int soGiay) const
{
    CTime Time;
    Time.gio = this->gio;
    Time.phut = this->phut;
    Time.giay = this->giay;
    Time.giay = Time.giay - soGiay;
    while (Time.giay <= 0)
    {
        Time.giay = 60 + Time.giay;
        Time.phut--;
    }
    while (Time.phut <= 0)
    {
        Time.phut = 60 + Time.phut;
        Time.gio--;
    }
    if (Time.gio <= 0)
        Time.gio = 0;
    return Time;
}
CTime CTime::TruCTS(const CTime &other) const
{
    CTime Time;
    int tongGiay = this->gio * 3600 + this->phut * 60 + this->giay - (other.gio * 3600 + other.phut * 60 + other.giay);
    Time.gio = tongGiay / 3600;
    Time.phut = (tongGiay % 3600) / 60;
    Time.giay = (tongGiay % 3600) % 60;
    return Time;
}
CTime CTime::ThemMotGiay() const
{
    CTime Time;
    Time.gio = this->gio;
    Time.phut = this->phut;
    Time.giay = this->giay;
    Time.giay++;
    if (Time.giay >= 60)
    {
        Time.giay = 0;
        Time.phut++;
        if (Time.phut >= 60)
        {
            Time.phut = 0;
            Time.gio++;
            if (Time.gio >= 24)
            {
                Time.gio = 0;
            }
        }
    }
    return Time;
}

CTime CTime::BotMotGiay() const
{
    CTime Time;
    Time.gio = this->gio;
    Time.phut = this->phut;
    Time.giay = this->giay;
    Time.giay--;
    if (Time.giay < 0)
    {
        Time.giay = 59;
        Time.phut--;
        if (Time.phut < 0)
        {
            Time.phut = 59;
            Time.gio--;
            if (Time.gio < 0)
            {
                Time.gio = 23;
            }
        }
    }
    return Time;
}
