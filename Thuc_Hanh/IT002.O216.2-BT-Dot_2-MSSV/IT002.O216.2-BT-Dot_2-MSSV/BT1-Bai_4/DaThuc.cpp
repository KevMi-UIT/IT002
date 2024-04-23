#include "DaThuc.h"
#include <iostream>
#include <vector>
istream &operator>>(istream &in, DaThuc &dt)
{
    cout << "Nhap so mu: ";
    in >> dt.somu;
    dt.a.resize(dt.somu + 1);
    cout << "Nhap cac he so: " << endl;
    for (int i = 0; i < dt.somu; i++)
    {
        in >> dt.a[i];
    }
    return in;
}
ostream &operator<<(ostream &out, const DaThuc &dt)
{
    for (int i = dt.somu; i >= 0; --i)
    {
        if (dt.a[i] != 0)
        {
            if (i < dt.somu)
            {
                out << " + ";
            }
            out << dt.a[i];
            if (i > 0)
            {
                if (i == 1)
                {
                    out << "x";
                }
                else
                {
                    out << "x^" << i;
                }
            }
        }
    }
    return out;
}

DaThuc DaThuc::operator+(const DaThuc &other)
{
    DaThuc result;
    int maxSize = max(this->somu, other.somu);
    result.somu = maxSize;
    result.a.resize(maxSize + 1);

    for (int i = 0; i <= maxSize; ++i)
    {
        int term1 = (i <= this->somu) ? this->a[i] : 0;
        int term2 = (i <= other.somu) ? other.a[i] : 0;
        result.a[i] = term1 + term2;
    }
    return result;
}
DaThuc DaThuc::operator-(const DaThuc &other)
{
    DaThuc result;
    int maxSize = max(this->somu, other.somu);
    result.somu = maxSize;
    result.a.resize(maxSize + 1);

    for (int i = 0; i <= maxSize; ++i)
    {
        int term1 = (i <= this->somu) ? this->a[i] : 0;
        int term2 = (i <= other.somu) ? other.a[i] : 0;
        result.a[i] = term1 - term2;
    }
    return result;
}
