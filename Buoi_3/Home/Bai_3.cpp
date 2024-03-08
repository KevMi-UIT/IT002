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
    float GetX() const;
    float GetY() const;
    static float TinhKhoangCach(const Point &, const Point &);
};

int main()
{
    Point x, y;
    x.Nhap();
    y.Nhap();
    cout << "Khoang cach giua 2 diem: " << Point::TinhKhoangCach(x, y) << endl;
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

float Point::GetX() const
{
    return this->x;
}

float Point::GetY() const
{
    return this->y;
}

float Point::TinhKhoangCach(const Point &self, const Point &other)
{
    return sqrt(pow(self.GetX() - other.GetX(), 2) + pow(self.GetY() - other.GetY(), 2));
}
