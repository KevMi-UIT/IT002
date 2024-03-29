#include "Diem.h"
#include <iostream>
using namespace std;

Diem::Diem()
{
    x = y = 0;
}
Diem ::~Diem()
{
}

void Diem::Nhap()
{
    cout << "Nhap x, y: ";
    cin >> this->x >> this->y;
}

void Diem::Xuat() const
{
    cout << "Toa do cua diem: ";
    cout << "(" << this->x << ", " << this->y << ")" << endl;
}

void Diem::setX(float initX)
{
    this->x = initX;
}
void Diem::setY(float initY)
{
    this->y = initY;
}

float Diem::getX() const
{
    return this->x;
}

float Diem::getY() const
{
    return this->y;
}

Diem Diem::TinhTien(float a, float b)
{
    Diem temp;
    temp.setX(this->x + a);
    temp.setY(this->y + b);
    return temp;
}
