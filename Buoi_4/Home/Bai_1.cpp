#define MAX 200
#define MIN -200

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

int MAX_WIDTH = to_string(MAX).length() + 3;

class cArray
{
  private:
    int n;
    vector<int> v;

  public:
    cArray();
    void NhapMang();
    void XuatMang() const;
    void TaoNgauNhien();
    int DemLanXuatHienX(const int &x) const;
    bool KiemTraTangDan() const;
    int TimLeNhoNhat() const;
    void SapXepTangDan();
};

int main()
{
    cArray myArray;

    // Nhap mang
    myArray.NhapMang();

    // Xuat mang
    cout << "Xuat mang da nhap" << endl;
    myArray.XuatMang();

    // Tao ngau nhien
    cout << "Tao mang ngau nhien" << endl;
    myArray.TaoNgauNhien();
    myArray.XuatMang();

    // Dem so lan xuat hien x trong mang
    int x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "So lan xuat hien " << x << ": " << myArray.DemLanXuatHienX(x) << endl;

    // Kiem tra tang dan
    switch (myArray.KiemTraTangDan())
    {
    case false:
        cout << "Mang khong phai giam dan" << endl;
        break;
    case true:
        cout << "Mang giam dan" << endl;
        break;
    }

    // Tim phan tu le nho nhat
    int minOdd = myArray.TimLeNhoNhat();
    switch (minOdd)
    {
    case 0:
        cout << "Khong co phan tu le nao" << endl;
        break;
    default:
        cout << "Phan tu le nho nhat trong mang: " << minOdd << endl;
        break;
    }

    // Sap xep tang dan
    cout << "Mang sap xep tang dan" << endl;
    myArray.SapXepTangDan();
    myArray.XuatMang();

    return 0;
}

cArray::cArray()
{
}

void cArray::NhapMang()
{
    cout << "Nhap n: ";
    cin >> this->n;
    this->v.resize(n);
    for (int i = 0; i < this->n; i++)
    {
        cout << "\tNhap v[" << i << "]: ";
        cin >> this->v[i];
    }
}

void cArray::XuatMang() const
{
    for (auto it : this->v)
        cout << setw(MAX_WIDTH) << it;
    cout << endl;
}

void cArray::TaoNgauNhien()
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        v[i] = rand() % (MAX - MIN) - MAX + 1;
}

int cArray::DemLanXuatHienX(const int &x) const
{
    int count = 0;
    for (auto it : this->v)
        if (it == x)
            count++;
    return count;
}

bool cArray::KiemTraTangDan() const
{
    for (int i = 0; i < this->n - 1; i++)
        if (v[i] > v[i + 1])
            return false;
    return true;
}

int cArray::TimLeNhoNhat() const
{
    int res = 0;
    for (auto it : this->v)
        if (abs(it) % 2 == 1)
            switch (res)
            {
            case 0:
                res = it;
                break;
            default:
                if (it < res)
                    res = it;
                break;
            }
    return res;
}

void cArray::SapXepTangDan()
{
    sort(this->v.begin(), this->v.end());
}
