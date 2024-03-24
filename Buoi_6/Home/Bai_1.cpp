#include <iostream>
using namespace std;

class ComplexNum
{
  private:
    int real;
    int imagine;

  public:
    ComplexNum() : real{0}, imagine(0){};
    ComplexNum(const int &, const int &);
};

int main()
{

    return 0;
}

ComplexNum::ComplexNum(const int &input_real, const int &input_imagine = 0)
{
    this->real = input_real;
    this->imagine = input_imagine;
}
