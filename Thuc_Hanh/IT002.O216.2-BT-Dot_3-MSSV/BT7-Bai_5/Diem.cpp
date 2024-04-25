#include "Diem.h"
#include <cmath>

Diem::Diem(const float &x, const float &y)
{
    this->x = x;
    this->y = y;
}

void Diem::setX(const float &x)
{
    this->x = x;
}

void Diem::setY(const float &y)
{
    this->y = y;
}

float Diem::getX() const
{
    return this->x;
}

float Diem::getY() const
{
    return this->y;
}

istream &operator>>(istream &is, Diem &d)
{
    cout << "Nhap x: ";
    is >> d.x;
    cout << "Nhap y: ";
    is >> d.y;
    return is;
}

ostream &operator<<(ostream &os, const Diem &d)
{
    os << "(" << d.x << ", " << d.y << ")";
    return os;
}

float Diem::tinhKhoangCach(Diem d)
{
    return sqrt(pow(this->x - d.x, 2) + pow(this->y - d.y, 2));
}
