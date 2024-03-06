#include <iostream>
#include <cmath>
using namespace std;
struct PhanSo
{
    int tu;
    int mau;
};
PhanSo RutGon(PhanSo &);

PhanSo operator+(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.tu = A.tu * B.mau + B.tu * A.mau;
    C.mau = A.mau * B.mau;
    return RutGon(C);
}
PhanSo operator-(PhanSo A, PhanSo B)
{
    PhanSo minus_1 = {-1, 1};
    PhanSo C = A + (minus_1 * B);
    return RutGon(C);
}
PhanSo operator*(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.tu = A.tu * B.tu;
    C.mau = A.mau * B.mau;
    return RutGon(C);
}
PhanSo operator/(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.tu = A.tu * B.mau;
    C.mau = A.mau * B.tu;
    return RutGon(C);
}
void input(PhanSo &a)
{
    do
    {
        cout << "Nhap phan so: ";
        cin >> a.tu >> a.mau;
    } while (a.mau == 0);
}
void output(PhanSo a)
{
    if (a.mau == 1)
    {
        cout << a.tu << endl;
    }
    else if (a.mau == -1)
    {
        cout << "-" << a.tu << endl;
    }
    else
    {
        cout << a.tu << "/" << a.mau << endl;
    }
}
int maxUoc(int a, int b)
{
    int m = abs(a);
    int n = abs(b);
    while (m * n != 0)
    {
        if (m > n)
            m -= n;
        else
            n -= m;
    }
    return m + n;
}
PhanSo RutGon(PhanSo &a)
{
    int i = maxUoc(a.mau, a.tu);
    a.mau /= i;
    a.tu /= i;
    return a;
}
int main()
{
    PhanSo a, b;
    input(a);
    input(b);
    cout << "a + b = ";
    output(a + b);
    cout << "a - b = ";
    output(a - b);
    cout << "a * b = ";
    output(a * b);
    cout << "a / b = ";
    output(a / b);
    return 0;
}
