#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;

public:
    //PhanSo();
    //PhanSo(int, int); // constructor
    void NhapPhanSo();
    void Print() const;
    int LayTu() const;
    int LayMau() const;
    PhanSo operator+(PhanSo&) const;
};

int main()
{
    // Nhap phan so
    PhanSo ps1;
    ps1.NhapPhanSo();
    // Khoi tao phan so
    PhanSo ps2(4, 5);
    // Xuat phan so
    ps2.Print();
    // Lay gia tri phan so
    cout << "Tu cua phan so 2: " << ps2.LayTu() << endl;
    cout << "Mau cua phan so 2: " << ps2.LayMau() << endl;
    // Tong 2 phan so
    PhanSo tong;
    tong = ps1 + ps2;
    tong.Print();
    return 0;
}

PhanSo::PhanSo()
{
    this->tu = 0;
    this->mau = 1;
}

void PhanSo::NhapPhanSo()
{
    cout << "Nhap tu: ";
    cin >> this->tu;
    cout << "Nhap mau: ";
    cin >> this->mau;
}

PhanSo::PhanSo(int initTu, int initMau)
{
    this->tu = initTu;
    this->mau = initMau;
}

void PhanSo::Print() const
{
    cout << "\tTu: " << this->tu << endl;
    cout << "\tMau: " << this->mau << endl;
}

int PhanSo::LayTu() const
{
    return this->tu;
}

int PhanSo::LayMau() const
{
    return this->mau;
}

PhanSo PhanSo::operator+(PhanSo& other) const
{
    PhanSo res = { 0, 1 };
    res.tu = this->tu * other.mau + this->mau * other.tu;
    res.mau = this->mau * other.mau;
    return res;
}
