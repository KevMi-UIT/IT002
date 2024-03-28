#pragma once
#include <iosfwd>

using namespace std;
class ComplexNum
{
  private:
    double real;
    double imagine;

  public:
    ComplexNum() : real{0}, imagine{0} {};
    ComplexNum(const double &, const double &);
    ComplexNum operator-();
    ComplexNum operator+(const ComplexNum &) const;
    ComplexNum operator-(const ComplexNum &) const;
    ComplexNum operator*(const ComplexNum &) const;
    ComplexNum operator/(const ComplexNum &) const;
    bool operator==(const ComplexNum &) const;
    friend ostream &operator<<(ostream &output, const ComplexNum &);
    friend istream &operator>>(istream &input, const ComplexNum &);
};