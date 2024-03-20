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
    int tu;
    int mau;

  public:
    PhanSo();
    ~PhanSo();
    PhanSo(int, int);
    void NhapPhanSo();
    void RutGon();
    void XuatPhanSo() const;
    void setTu(int);
    void setMau(int);
    int getTu();
    int getMau();
    bool TuSoNguyenTo();
};

class arrPhanSo
{
  public:
    void NhapMangPhanSo();
    void XuatMangPhanSo() const;
    void TaoMangNgauNhien();
    PhanSo TimPhanSoMax() const;
    int DemTuSoNguyenTo();
    void SapXepTangDan();

  private:
    int n;
    vector<PhanSo> v;
};

int maxUoc(int, int);
bool SoNguyenTo(int);
bool Compare(PhanSo, PhanSo);

int main()
{
    arrPhanSo array1, array2;

    // 1. Nhập mảng phân số
    array1.NhapMangPhanSo();

    // 2. Xuất danh sách các phân số
    cout << "Danh sach cac phan so: " << endl;
    array1.XuatMangPhanSo();

    // 3. Tạo n phân số ngẫu nhiên
    array2.TaoMangNgauNhien();
    cout << "Danh sach cac phan so ngau nhien: " << endl;
    array2.XuatMangPhanSo();

    // 4. Tìm phân số có giá trị lớn nhất
    cout << "Phan so lon nhat trong mang 1 la: ";
    array1.TimPhanSoMax().XuatPhanSo();
    cout << endl;

    // 5. Đếm số phân số có tử là số nguyên tố
    cout << "So luong phan so co tu la so nguyen to: ";
    cout << array1.DemTuSoNguyenTo();
    cout << endl;

    // 6. Sắp xếp các phân số trong mảng theo thứ tự tăng dần
    array1.SapXepTangDan();
    cout << "Danh sach cac phan so sap xep tang dan trong mang 1: " << endl;
    array1.XuatMangPhanSo();
    return 0;
}

PhanSo::PhanSo()
{
    this->tu = 0;
    this->mau = 1;
}

PhanSo::~PhanSo()
{
}

PhanSo::PhanSo(int initTu, int initMau)
{
    this->tu = initTu;
    this->mau = initMau;
}

void PhanSo::NhapPhanSo()
{
    do
    {
        cout << "\tNhap tu so: ";
        cin >> this->tu;
        cout << "\tNhap mau so: ";
        cin >> this->mau;
    } while (this->mau == 0);
}

void PhanSo::XuatPhanSo() const
{
    if (this->mau == 1)
        cout << this->tu;
    else
        cout << this->tu << "/" << this->mau;
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

void PhanSo::RutGon()
{
    int i = maxUoc(this->mau, this->tu);
    if (this->mau < 0)
    {
        this->mau /= (-i);
        this->tu /= (-i);
    }
    else
    {
        this->mau /= i;
        this->tu /= i;
    }
}

void PhanSo::setTu(int initTu)
{
    this->tu = initTu;
}

void PhanSo::setMau(int initMau)
{
    this->mau = initMau;
}

int PhanSo::getTu()
{
    return this->tu;
}

int PhanSo::getMau()
{
    return this->mau;
}

bool SoNguyenTo(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0)
            return false;
    return true;
}

bool PhanSo::TuSoNguyenTo()
{
    return SoNguyenTo(this->tu);
}

void arrPhanSo::NhapMangPhanSo()
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

void arrPhanSo::XuatMangPhanSo() const
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

void arrPhanSo::TaoMangNgauNhien()
{
    cout << "Nhap so luong phan so ngau nhien: ";
    cin >> this->n;
    this->v.resize(n);
    srand(time(NULL));
    for (int i = 0; i < this->n; i++)
    {
        v[i].setTu(rand() % (MAX - MIN) - MAX + 1);
        v[i].setMau(rand() % (MAX - MIN) - MAX + 1);
    }
}

PhanSo arrPhanSo::TimPhanSoMax() const
{
    PhanSo temp = this->v[0];
    for (auto it : this->v)
    {
        if (float(it.getTu()) / it.getMau() > float(temp.getTu()) / temp.getMau())
            temp = it;
    }
    return temp;
}

int arrPhanSo::DemTuSoNguyenTo()
{
    int count = 0;
    for (auto it : this->v)
    {
        if (it.TuSoNguyenTo() == 1)
            count++;
    }
    return count;
}

bool Compare(PhanSo a, PhanSo b)
{
    return float(a.getTu()) / a.getMau() < float(b.getTu()) / b.getMau();
}

void arrPhanSo::SapXepTangDan()
{
    sort(this->v.begin(), this->v.end(), Compare);
}
