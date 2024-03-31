#define MAX 200
#define MIN -200

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class PhanSo
{
  private:
    int tuso;
    int mauso;

  public:
    PhanSo(int t = 0, int m = 1);
    // PhanSo(const PhanSo &p);
    ~PhanSo();
    int LayTu();
    int LayMau();
    void GanTu(int);
    void GanMau(int);
    void XuatPhanSo() const;
    void NhapPhanSo();
    bool operator>(PhanSo &);
    PhanSo operator+(PhanSo &) const;
    PhanSo operator-(PhanSo &) const;
    PhanSo RutGon();
};

class DSPhanSo
{
  public:
    void NhapMangPhanSo();
    void XuatMangPhanSo() const;
    void TaoMangNgauNhien();
    PhanSo TimPhanSoMax() const;
    int DemTuSoNguyenTo();
    void SapXepTangDan();
    PhanSo Tong();

  private:
    int n;
    vector<PhanSo> v;
};

int maxUoc(int, int);

int main()
{
    DSPhanSo array1;

    // 1. Nhập mảng phân số
    array1.NhapMangPhanSo();
    cout << endl;

    // 2. Xuất danh sách các phân số
    cout << "Danh sach cac phan so: " << endl;
    array1.XuatMangPhanSo();

    // 3. Tính tổng các phân số có trong mảng
    cout << "Tong cac phan so trong mang: ";
    array1.Tong().XuatPhanSo();
    cout << endl;

    // 4. Tìm phân số có giá trị lớn nhất
    cout << "Phan so lon nhat trong mang 1 la: ";
    array1.TimPhanSoMax().XuatPhanSo();
    cout << endl;
}

PhanSo::~PhanSo()
{
}

PhanSo::PhanSo(int initTu, int initMau)
{
    this->tuso = initTu;
    this->mauso = initMau;
}

bool PhanSo::operator>(PhanSo &A)
{
    return (float(this->LayTu()) / (this->LayMau()) > float(A.LayTu()) / (A.LayMau()));
}

PhanSo PhanSo::operator+(PhanSo &A) const
{
    return PhanSo(this->tuso * A.mauso + this->mauso * A.tuso, this->mauso * A.mauso);
}
PhanSo PhanSo::operator-(PhanSo &A) const
{
    return PhanSo(this->tuso * A.mauso - this->mauso * A.tuso, this->mauso * A.mauso);
}

void PhanSo::NhapPhanSo()
{
    do
    {
        cout << "\tNhap tu so: ";
        cin >> this->tuso;
        cout << "\tNhap mau so: ";
        cin >> this->mauso;
    } while (this->mauso == 0);
}

void PhanSo::XuatPhanSo() const
{
    if (this->mauso == 1)
        cout << this->tuso;
    else
        cout << this->tuso << "/" << this->mauso;
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

PhanSo PhanSo::RutGon()
{
    PhanSo temp;
    int i = maxUoc(this->mauso, this->tuso);
    if (this->mauso < 0)
    {
        temp.mauso = this->mauso / (-i);
        temp.tuso = this->tuso / (-i);
    }
    else
    {
        temp.mauso = this->mauso / i;
        temp.tuso = this->tuso / i;
    }
    return temp;
}

void PhanSo::GanTu(int initTu)
{
    this->tuso = initTu;
}

void PhanSo::GanMau(int initMau)
{
    this->mauso = initMau;
}

int PhanSo::LayTu()
{
    return this->tuso;
}

int PhanSo::LayMau()
{
    return this->mauso;
}

void DSPhanSo::NhapMangPhanSo()
{
    cout << "Nhap so luong phan so: ";
    cin >> this->n;
    this->v.resize(n);
    for (int i = 0; i < this->n; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << endl;
        v[i].NhapPhanSo();
    }
    cout << endl;
}

void DSPhanSo::XuatMangPhanSo() const
{
    for (int i = 0; i < this->n; i++)
    {
        v[i].XuatPhanSo();
        if (i == this->n - 1)
            cout << ".";
        else
            cout << "; ";
    }
    cout << endl << endl;
}

PhanSo DSPhanSo::TimPhanSoMax() const
{
    PhanSo temp = this->v[0];
    for (auto it : this->v)
    {
        if (it > temp)
            temp = it;
    }
    return temp;
}

PhanSo DSPhanSo::Tong()
{
    PhanSo temp;
    for (auto it : this->v)
        temp = temp + it;
    return temp.RutGon();
}
