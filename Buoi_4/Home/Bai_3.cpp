#include <cmath>
#include <iostream>
using namespace std;

class DonThuc
{
  public:
    DonThuc();
    ~DonThuc();
    void NhapDonThuc();
    void ThayDoiDonThuc();
    void XuatDonThuc() const;
    void TinhGiaTri();
    DonThuc TinhDaoHam();
    DonThuc operator+(DonThuc &) const;
    int getBac();

  private:
    int x;
    int soMu;
    int heSo;
};

int main()
{
    DonThuc P, Q, J;
    P.NhapDonThuc();
    cout << "Don thuc : ";
    P.XuatDonThuc();
    cout << "Thay doi thong tin don thuc: " << endl;
    P.ThayDoiDonThuc();
    P.XuatDonThuc();

    cout << "Gia tri cua don thuc : ";
    P.TinhGiaTri();

    cout << "Sau khi dao ham: ";
    P.TinhDaoHam().XuatDonThuc();

    cout << "Nhap 2 don thuc Q va J: " << endl;
    do
    {
        Q.NhapDonThuc();
        J.NhapDonThuc();
    } while (Q.getBac() != J.getBac());
    cout << "Tong hai don thuc Q va J: ";
    (Q + J).XuatDonThuc();
    return 0;
}

DonThuc::DonThuc()
{
    this->x = this->soMu = this->heSo = 0;
}

DonThuc::~DonThuc()
{
}

void DonThuc::NhapDonThuc()
{
    cout << "Bac cua don thuc: ";
    cin >> this->soMu;
    cout << "He so cua don thuc: ";
    cin >> this->heSo;
}

void DonThuc::XuatDonThuc() const
{

    if (this->heSo == 0)
        cout << "0";
    else if (this->soMu == 0)
        cout << this->heSo;
    else
        cout << this->heSo << "x^" << this->soMu;
    cout << endl;
}

void DonThuc::TinhGiaTri()
{
    cout << "Nhap gia tri cua x: ";
    cin >> this->x;
    cout << "Gia tri cua don thuc: " << (this->heSo) * pow(this->x, this->soMu) << endl;
}

DonThuc DonThuc::TinhDaoHam()
{
    DonThuc res;
    res.heSo = (this->soMu) * (this->heSo);
    res.soMu = this->soMu - 1;
    return res;
}

DonThuc DonThuc::operator+(DonThuc &b) const
{
    DonThuc res;
    res.heSo = this->heSo + b.heSo;
    res.soMu = this->soMu;
    return res;
}

int DonThuc::getBac()
{
    return this->soMu;
}

void DonThuc::ThayDoiDonThuc()
{
    this->NhapDonThuc();
}