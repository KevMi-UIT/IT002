/*
3
1
3
2
5
4
3
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct PhanSo
{
    int tu;
    int mau;
};
typedef PhanSo PHANSO;

struct DanhSach
{
    vector<PHANSO> danhSach;
    int soLuong;
};
typedef DanhSach DANHSACH;

PHANSO operator+(const PHANSO &A, const PHANSO &B)
{
    PHANSO c;
    c.tu = A.tu * B.mau + A.mau * B.tu;
    c.mau = A.mau * B.mau;
    return c;
}

void NhapPhanSo(PHANSO &);
void XuatPhanSo(const PHANSO &);
void NhapDanhSach(DANHSACH &);
PHANSO TongCacPhanSo(const DANHSACH &);
bool SoSanhPhanSo(const PHANSO &, const PHANSO &);
PHANSO TimPhanSoMax(DANHSACH);
void RutGon(PhanSo &);
int main()
{
    DANHSACH ds;
    NhapDanhSach(ds);
    // Y 1
    cout << "Tong cac phan so:" << endl;
    XuatPhanSo(TongCacPhanSo(ds));
    // Y 2
    cout << "Phan so lon nhat:" << endl;
    XuatPhanSo(TimPhanSoMax(ds));
    return 0;
}

int maxUoc(int a, int b)
{
    int m = abs(a);
    int n = abs(b);
    while (m * n != 0)
    {
        if (m > n)
            m -= n;
        else
            n -= m;
    }
    return m + n;
}

void RutGon(PhanSo &a)
{
    int i = maxUoc(a.mau, a.tu);
    a.mau /= i;
    a.tu /= i;
}

void NhapPhanSo(PHANSO &a)
{
    do
    {
        cout << "\t\tNhap tu: ";
        cin >> a.tu;
        cout << "\t\tNhap mau: ";
        cin >> a.mau;
    } while (a.mau == 0);
}

void XuatPhanSo(const PHANSO &a)
{
    if (a.mau == 1)
        cout << a.tu;
    else if (a.mau == -1)
        cout << "-" << a.tu;
    else
        cout << a.tu << "/" << a.mau;
    cout << endl;
}

void NhapDanhSach(DANHSACH &ds)
{
    cout << "Nhap so luong phan so: ";
    cin >> ds.soLuong;
    ds.danhSach.resize(ds.soLuong);
    for (int i = 0; i < ds.soLuong; i++)
    {
        cout << "\tNhap phan so thu " << i + 1 << endl;
        NhapPhanSo(ds.danhSach[i]);
    }
}

PHANSO TongCacPhanSo(const DANHSACH &ds)
{
    PHANSO phanSo = {0, 1};
    for (auto it : ds.danhSach)
        phanSo = phanSo + it;
    RutGon(phanSo);
    return phanSo;
}

bool SoSanhPhanSo(const PHANSO &A, const PHANSO &B)
{
    return ((float)A.tu / A.mau) > ((float)B.tu / B.mau);
}

PHANSO TimPhanSoMax(DANHSACH ds)
{
    sort(ds.danhSach.begin(), ds.danhSach.end(), SoSanhPhanSo);
    return ds.danhSach[0];
}
