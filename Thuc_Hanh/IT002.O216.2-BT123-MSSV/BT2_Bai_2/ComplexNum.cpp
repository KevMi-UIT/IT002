#include "ComplexNum.h"
#include <iostream>
using namespace std;

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

ostream &operator<<(ostream &output, const ComplexNum &num)
{
    output << num.real << " + " << num.imagine << "i";
    return output;
}

istream &operator>>(istream &input, ComplexNum &num)
{
    cout << "Nhap phan thuc: ";
    input >> num.real;
    cout << "Nhap phan ao: ";
    input >> num.imagine;
    return input;
}
