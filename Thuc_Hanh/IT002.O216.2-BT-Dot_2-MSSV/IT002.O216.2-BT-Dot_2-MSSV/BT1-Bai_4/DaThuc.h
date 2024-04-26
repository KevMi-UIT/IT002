#pragma once
#include <iostream>
#include <vector>
using namespace std;
class DaThuc
{
  private:
    int somu;
    vector<int> a;

  public:
    DaThuc operator+(const DaThuc &);
    DaThuc operator-(const DaThuc &);
    friend istream &operator>>(istream &in, DaThuc &dt);
    friend ostream &operator<<(ostream &out, const DaThuc &dt);
};
