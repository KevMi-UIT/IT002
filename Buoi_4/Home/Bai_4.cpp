#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Dathuc
{
  private:
    int bac;
    vector<int> Heso;

  public:
    Dathuc(int bac = 0) : bac(bac)
    {
        Heso.resize(bac + 1);
    }
    void Nhap();
    void Xuat() const;
    void Giatri(int x) const;
    Dathuc CongDaThuc(const Dathuc &dt) const;
    Dathuc TruDaThuc(const Dathuc &dt) const;
};

int main()
{
    Dathuc dt1, dt2;
    cout << "Nhap da thuc 1: " << endl;
    dt1.Nhap();
    cout << "Nhap da thuc 2: " << endl;
    dt2.Nhap();

    cout << "Da thuc thu nhat: ";
    dt1.Xuat();
    cout << "Da thuc thu hai: ";
    dt2.Xuat();

    Dathuc tong = dt1.CongDaThuc(dt2);
    cout << "Tong hai da thuc: ";
    tong.Xuat();

    Dathuc hieu = dt1.TruDaThuc(dt2);
    cout << "Hieu hai da thuc: ";
    hieu.Xuat();

    int x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Gia tri cua da thuc 1 la: ";
    dt1.Giatri(x);
    cout << "Gia tri cua da thuc 2 la: ";
    dt2.Giatri(x);

    return 0;
}

void Dathuc::Nhap()
{
    cout << "Nhap bac da thuc: ";
    cin >> bac;
    Heso.resize(bac + 1);
    cout << "Nhap cac he so " << endl;
    for (int i = bac; i >= 0; --i)
    {
        cin >> Heso[i];
    }
}

void Dathuc::Xuat() const
{
    for (int i = bac; i >= 0; --i)
    {
        if (Heso[i] != 0)
        {
            if (i < bac)
            {
                cout << " + ";
            }
            cout << Heso[i];
            if (i > 0)
            {
                cout << "x^" << i;
            }
        }
    }
    cout << endl;
}

void Dathuc::Giatri(int x) const
{
    long long tong = 0;
    for (int i = bac; i >= 0; --i)
    {
        tong += Heso[i] * pow(x, i);
    }
    cout << tong << endl;
}

Dathuc Dathuc::CongDaThuc(const Dathuc &dt) const
{
    int maxBac = max(bac, dt.bac);
    Dathuc tong(maxBac);
    for (int i = 0; i <= maxBac; ++i)
    {
        int hs1 = (i <= bac) ? Heso[i] : 0;
        int hs2 = (i <= dt.bac) ? dt.Heso[i] : 0;
        tong.Heso[i] = hs1 + hs2;
    }
    return tong;
}

Dathuc Dathuc::TruDaThuc(const Dathuc &dt) const
{
    int maxBac = max(bac, dt.bac);
    Dathuc hieu(maxBac);
    for (int i = 0; i <= maxBac; ++i)
    {
        int hs1 = (i <= bac) ? Heso[i] : 0;
        int hs2 = (i <= dt.bac) ? dt.Heso[i] : 0;
        hieu.Heso[i] = hs1 - hs2;
    }
    return hieu;
}
