#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;

public:
    PhanSo();
    PhanSo(int, int);
    void NhapPhanSo();
    void Print() const;
    int LayTu() const;
    int LayMau() const;
    PhanSo operator+(PhanSo &) const;
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
    tu = 0;
    mau = 1;
}

void PhanSo::NhapPhanSo()
{
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}

PhanSo::PhanSo(int initTu, int initMau)
{
    tu = initTu;
    mau = initMau;
}

void PhanSo::Print() const
{
    cout << "\tTu: " << tu << endl;
    cout << "\tMau: " << mau << endl;
}

int PhanSo::LayTu() const
{
    return tu;
}

int PhanSo::LayMau() const
{
    return mau;
}

PhanSo PhanSo::operator+(PhanSo &other) const
{
    PhanSo res;
    res.tu = tu * other.mau + mau * other.tu;
    res.mau = mau * other.mau;
    return res;
}