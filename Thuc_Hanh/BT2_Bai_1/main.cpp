#include "phanso.h"
#include <iostream>
using namespace std;

int main()
{
    PhanSo a, b;
    a.Nhap();
    b.Nhap();
    cout << "a + b = ";
    (a + b).Rutgon().Xuat();
    cout << "a - b = ";
    (a - b).Rutgon().Xuat();
    cout << "a * b = ";
    (a * b).Rutgon().Xuat();
    cout << "a / b = ";
    (a / b).Rutgon().Xuat();
    return 0;
}
