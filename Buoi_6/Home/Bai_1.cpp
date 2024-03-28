#include <iostream>
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
    ComplexNum operator<<(const ComplexNum &) const;
    ComplexNum operator>>(const ComplexNum &) const;
};

int main()
{

    return 0;
}

ComplexNum::ComplexNum(const double &input_real, const double &input_imagine = 0)
{
    this->real = input_real;
    this->imagine = input_imagine;
}

ComplexNum ComplexNum::operator-()
{
    return ComplexNum(-this->real, this->imagine);
}

ComplexNum ComplexNum::operator+(const ComplexNum &other) const
{
    double real = this->real + other.real;
    double imagine = this->imagine + other.imagine;
    return ComplexNum(real, imagine);
}

ComplexNum ComplexNum::operator-(const ComplexNum &other) const
{
    double real = this->real - other.real;
    double imagine = this->imagine - other.imagine;
    return ComplexNum(real, imagine);
}

ComplexNum ComplexNum::operator*(const ComplexNum &other) const
{
    double real = this->real * other.real - this->imagine * other.imagine;
    double imagine = this->real * other.imagine + this->imagine * other.real;
    return ComplexNum(real, imagine);
}

ComplexNum ComplexNum::operator/(const ComplexNum &other) const
{
    double real = (this->real * other.real + this->imagine * other.imagine) /
                  (other.real * other.real + other.imagine * other.imagine);
    double imagine = (other.real * this->imagine - this->real * other.imagine) /
                     (other.real * other.real + other.imagine * other.imagine);
    return ComplexNum(real, imagine);
}

bool ComplexNum::operator==(const ComplexNum &other) const
{
    return ((this->real == other.real) && (this->imagine == other.imagine));
}

/* ComplexNum ComplexNum::operator<<(const ComplexNum &other) const */
/* { */
/* } */
/* ComplexNum ComplexNum::operator>>(const ComplexNum &other) const */
/* { */
/* } */
