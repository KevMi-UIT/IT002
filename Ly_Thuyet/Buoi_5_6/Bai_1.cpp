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
    friend ostream &operator<<(ostream &output, const ComplexNum &);
    friend istream &operator>>(istream &input, ComplexNum &);
};

int main()
{
    ComplexNum num1, num2;
    cout << "Nhap so phuc 1: " << endl;
    cin >> num1;
    cout << "Nhap so phuc 2: " << endl;
    cin >> num2;
    cout << "So phuc 1: " << num1 << endl;
    cout << "So phuc 2: " << num2 << endl;
    cout << "So phuc 1 + So phuc 2: " << num1 + num2 << endl;
    cout << "So phuc 1 - So phuc 2: " << num1 - num2 << endl;
    cout << "So phuc 1 * So phuc 2: " << num1 * num2 << endl;
    cout << "So phuc 1 / So phuc 2: " << num1 / num2 << endl;
    if (num1 == num2)
        cout << "so phuc 1 == so phuc 2 == " << num1 << endl;
    else
        cout << "so phuc 1 = " << num1 << " != " << "so phuc 2 = " << num2 << endl;
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
