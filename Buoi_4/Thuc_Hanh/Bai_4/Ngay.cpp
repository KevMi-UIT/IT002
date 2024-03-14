#include "Ngay.h"
#include <iostream>

using namespace std;

void Ngay::Nhap()
{
	cout << "Nhap ngay: ";
	cin >> this->day;
	cout << "Nhap thang: ";
	cin >> this->month;
	cout << "Nhap nam: ";
	cin >> this->year;
}

Ngay Ngay::KeTiep() const
{
	int stt = this->SoThuTu();
	stt++;
	return TimNgay(stt);
}

void Ngay::Xuat() const
{
	cout << "Ngay: " << this->day << endl;
	cout << "Thang: " << this->month << endl;
	cout << "Nam: " << this->year;
}

int Ngay::ktNhuan() const
{
	if (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0)
		return 1;
	return 0;
}

int Ngay::SoNgayToiDaTrongThang() const
{
	int ngaythang[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (this->ktNhuan())
		ngaythang[1] = 29;
	return ngaythang[this->month - 1];
}

int Ngay::SoNgayToiDaTrongNam() const
{
	if (this->ktNhuan())
		return 366;
	return 365;
}

int Ngay::SoThuTuTrongNam() const
{
	int stt = 0;
	for (int i = 1; i < this->month; i++)
	{
		Ngay temp = { 1, i, this->year };
		stt += temp.SoNgayToiDaTrongThang();
	}
	return (stt + this->day);
}

int Ngay::SoThuTu() const
{
	int stt = 0;
	for (int i = 1; i < this->year; i++)
	{
		Ngay temp = { 1, 1, i };
		stt += temp.SoNgayToiDaTrongNam();
	}
	return (stt + this->SoThuTuTrongNam());
}

Ngay Ngay::TimNgay(const int& nam, int& stt)
{
	Ngay temp = { 1, 1, nam };
	temp.month = 1;
	while (stt > temp.SoNgayToiDaTrongThang())
	{
		stt = stt - temp.SoNgayToiDaTrongThang();
		temp.month++;
	}
	temp.day = stt;
	return temp;
}

Ngay Ngay::TimNgay(int& stt)
{
	int nam = 1;
	int sn = 365;
	while (stt > sn)
	{
		stt = stt - sn;
		nam++;
		Ngay temp = { 1, 1, nam };
		sn = temp.SoNgayToiDaTrongNam();
	}
	return TimNgay(nam, stt);
}