#include "Diem.h"
#include <iostream>
using namespace std;
Diem::Diem()
{
    x = y = 0;
}
Diem::~Diem()
{
}
void Diem::nhap()
{
    cout << "Nhap hoanh do: ";
    cin >> this->x;
    cout << "Nhap tung do: ";
    cin >> this->y;
}
void Diem::xuat()
{
    cout << "(" << this->x << "," << y << ")" << endl;
}
void Diem::tinhtien(int a, int b)
{
    this->x += a;
    this->y += b;
}
void Diem::thuphong(int k)
{
    this->x *= k;
    this->y *= k;
}
void Diem::quay(int rad)
{
    this->x = x * cos(rad) - y * sin(rad);
    this->y = x * sin(rad) + y * cos(rad);
}
