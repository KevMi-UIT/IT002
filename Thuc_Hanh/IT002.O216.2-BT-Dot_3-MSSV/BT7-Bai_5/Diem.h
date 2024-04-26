#pragma once
#include <iostream>
using namespace std;

class Diem
{
  private:
    float x;
    float y;

  public:
    Diem() : x(0), y(0)
    {
    }
    Diem(const float &, const float &);
    void setX(const float &);
    void setY(const float &);
    float getX() const;
    float getY() const;
    friend istream &operator>>(istream &, Diem &);
    friend ostream &operator<<(ostream &, const Diem &);
    static float tinhKhoangCach(const Diem &, const Diem &);
    ~Diem() = default;
};
