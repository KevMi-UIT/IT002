#include "Diem.h";
#include "TamGiac.h";
#include <iostream>
using namespace std;
int main()
{
    TamGiac A;
    int a, b, k, rad;
    A.Nhap();
    A.Xuat();
    cout << "Nhap toa do tinh tien: ";
    cin >> a >> b;
    A.Tinhtien(a, b);
    A.Xuat();
    cout << "Nhap chi so thu phong: ";
    cin >> k;
    A.Thuphong(k);
    A.Xuat();
    cout << "Nhap chi so quay: ";
    cin >> rad;
    A.Quay(rad);
    A.Xuat();
    return 0;
}
