#include <iostream>
#include <cmath>
using namespace std;

// Nhập xuất phân số, so sánh, rút gọn, tính toán +-*/
struct Phanso
{
    int tu;
    int mau;
};
Phanso SoSanh(Phanso, Phanso);
Phanso RutGon(Phanso &);

Phanso operator*(Phanso A, Phanso B)
{
    Phanso C;
    C.tu = A.tu * B.tu;
    C.mau = A.mau * B.mau;
    return RutGon(C);
}

Phanso operator+(Phanso A, Phanso B)
{
    Phanso c;
    c.tu = A.tu * B.mau + A.mau * B.tu;
    c.mau = A.mau * B.mau;
    return RutGon(c);
}

Phanso operator-(Phanso A, Phanso B)
{
    Phanso minus_1 = {-1, 1};
    return A + (minus_1 * B);
}

Phanso operator/(Phanso A, Phanso B)
{
    Phanso nghichDao = {B.mau, B.tu};
    return A * nghichDao;
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

Phanso RutGon(Phanso &a)
{
    int i = maxUoc(a.mau, a.tu);
    a.mau /= i;
    a.tu /= i;
    return a;
}

Phanso SoSanh(Phanso a, Phanso b)
{
    Phanso MAX;
    Phanso A = {a.tu * b.mau, a.mau * b.mau};
    Phanso B = {b.tu * a.mau, a.mau * b.mau};
    if (A.tu > B.tu)
        MAX = A;
    if (A.tu < B.tu)
        MAX = B;
    if (A.tu == B.tu)
        MAX = A;
    return MAX;
}
void Nhap(Phanso &a)
{
    do
    {
        cin >> a.tu >> a.mau;
    } while (a.mau == 0);
}

void Xuat(Phanso a)
{
    RutGon(a);
    if (a.mau == 1)
        cout << a.tu;
    else if (a.mau == -1)
        cout << "-" << a.tu;
    else
        cout << a.tu << "/" << a.mau;
    cout << endl;
}

int main()
{
    Phanso a, b;
    // câu a
    Nhap(a);
    Nhap(b);
    Xuat(a);
    Xuat(b);
    // câu b
    cout << "Phan so lon hon la ";
    Xuat(SoSanh(a, b));
    // câu c
    cout << "a + b = ";
    Xuat(a + b);
    cout << "a - b = ";
    Xuat(a - b);
    cout << "a * b = ";
    Xuat(a * b);
    cout << "a / b = ";
    Xuat(a / b);
    return 0;
}