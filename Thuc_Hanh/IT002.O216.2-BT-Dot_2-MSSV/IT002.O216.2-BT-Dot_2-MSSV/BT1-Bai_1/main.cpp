#include "CTimeSpan.h"
#include <iostream>
using namespace std;

int main()
{
    CTimeSpan a, b;
    cout << "Nhap CTimeSpan a:" << endl;
    a.Nhap();
    cout << "Nhap CTimeSpan b:" << endl;
    b.Nhap();

    cout << "a + b: " << endl;
    a.Cong(b).Xuat();

    cout << "a - b: " << endl;
    a.Tru(b).Xuat();

    cout << "a * b: " << endl;
    a.Nhan(b).Xuat();

    cout << "a / b: " << endl;
    a.Chia(b).Xuat();

    cout << "a == b: " << a.Bang(b) << endl;

    cout << "a != b: " << a.Khac(b) << endl;

    cout << "a < b: " << a.BeHon(b) << endl;

    cout << "a <= b: " << a.BeHonBang(b) << endl;

    cout << "a > b: " << a.LonHon(b) << endl;

    cout << "a >= b: " << a.LonHonBang(b) << endl;

    return 0;
}
