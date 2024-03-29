#include "DaGiac.h"
#include <iostream>
using namespace std;

DaGiac::~DaGiac()
{
}
DaGiac::DaGiac()
{
    soDiem = 0;
}

void DaGiac::Nhap()
{
    cout << "Nhap so diem: ";
    cin >> this->soDiem;
    this->Point.resize(soDiem);
    for (int i = 0; i < soDiem; i++)
    {
        cout << "Nhap diem thu " << i + 1 << ":" << endl;
        this->Point[i].Nhap();
    }
}

void DaGiac::Xuat() const
{
    for (int i = 0; i < soDiem; i++)
    {
        cout << "Toa do cua diem thu " << i + 1 << ": ";
        this->Point[i].Xuat();
        cout << endl;
    }
}

DaGiac DaGiac::TinhTien(float &a, float &b)
{
    DaGiac temp;
    temp.soDiem = this->soDiem;
    temp.Point.resize(soDiem);
    for (int i = 0; i < soDiem; i++)
    {
        temp.Point[i].setX((this->Point[i].TinhTien(a, b).getX()));
        temp.Point[i].setY((this->Point[i].TinhTien(a, b).getY()));
    }
    // temp.Point[i] = this->Point[i].TinhTien(a, b);
    return temp;
}

DaGiac DaGiac::Quay(float &rad)
{
    DaGiac temp;
    temp.soDiem = this->soDiem;
    temp.Point.resize(soDiem);
    for (int i = 0; i < this->soDiem; i++)
    {
        temp.Point[i].setX((this->Point[i].Quay(rad).getX()));
        temp.Point[i].setY((this->Point[i].Quay(rad).getY()));
    }
    return temp;
}

// Thu phong tai goc toa do
DaGiac DaGiac::ThuPhong(float &k)
{
    DaGiac temp;
    temp.soDiem = this->soDiem;
    temp.Point.resize(soDiem);
    for (int i = 0; i < soDiem; i++)
    {

        temp.Point[i].setX(this->Point[i].getX() * k);
        temp.Point[i].setY(this->Point[i].getY() * k);
    }
    return temp;
}
