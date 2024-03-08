#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    void Nhap();
    float GetX();
    float GetY();
};

class Circle
{
private:
    float duongKinh;
    Point tam;

public:
    void Nhap();
    float TinhDienTinh();
    float TinhChuVi();
};

int main()
{
    Circle myCircle;
    myCircle.Nhap();
    cout << "Chu vi: " << myCircle.TinhChuVi() << endl;
    cout << "Dien tich: " << myCircle.TinhDienTinh() << endl;
    return 0;
}

void Point::Nhap()
{
    cout << "Nhap diem: " << endl;
    cout << "\tx: ";
    cin >> this->x;
    cout << "\ty: ";
    cin >> this->y;
}

float Point::GetX()
{
    return this->x;
}

float Point::GetY()
{
    return this->y;
}

void Circle::Nhap()
{
    cout << "Nhap duong tron:" << endl;
    this->tam = Point();
    this->tam.Nhap();
    cout << "Nhap duong kinh: ";
    cin >> this->duongKinh;
}

float Circle::TinhDienTinh()
{
    return pow(this->duongKinh / 2, 2) * M_PI;
}

float Circle::TinhChuVi()
{
    return this->duongKinh / 2 * 2 * M_PI;
}