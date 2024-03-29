#include "TamGiac.h"
#include <iostream>
using namespace std;
void TamGiac::Nhap()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Nhap toa do diem thu " << i + 1 << ": ";
        cout << endl;
        this->arr[i].nhap();
    }
}
void TamGiac::Xuat()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Toa do diem thu " << i + 1 << ": ";
        this->arr[i].xuat();
    }
}
void TamGiac::Tinhtien(int a, int b)
{
    for (int i = 0; i < 3; i++)
    {
        this->arr[i].tinhtien(a, b);
    }
}
void TamGiac::Quay(int rad)
{
    for (int i = 0; i < 3; i++)
    {
        this->arr[i].quay(rad);
    }
}
void TamGiac::Thuphong(int k)
{
    for (int i = 0; i < 3; i++)
    {
        this->arr[i].thuphong(k);
    }
}
