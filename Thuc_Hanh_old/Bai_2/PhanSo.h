#pragma once
class PhanSo
{
private:
    int tu;
    int mau;
public:
    PhanSo();
    ~PhanSo();
    void Nhap();
    double getTu() const;
    double getMau() const;
    void Giatri(double, double, double, double);
    void Xuat() const;
    static void Max(PhanSo&, PhanSo&, PhanSo&);
};

