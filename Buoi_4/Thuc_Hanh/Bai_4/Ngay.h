#pragma once
class Ngay
{
private:
	int day;
	int month;
	int year;
public:
	void Nhap();
	Ngay(int day = 1, int month = 1, int year = 1) : day{ day }, month{ month }, year{ year } {};
	Ngay KeTiep() const;
	void Xuat() const;
private:
	int ktNhuan() const;
	int SoNgayToiDaTrongThang() const;
	int SoNgayToiDaTrongNam() const;
	int SoThuTuTrongNam() const;
	int SoThuTu() const;
	static Ngay TimNgay(const int&, int&);
	static Ngay TimNgay(int&);
};