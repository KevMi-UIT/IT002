#include "DaGiac.h"
#include "Diem.h"
#include <iostream>
using namespace std;

int main()
{
    DaGiac A;
    float k, a, b, rad;

    A.Nhap();
    A.Xuat();
    cout << "Nhap toa do tinh tien: ";
    cin >> a >> b;
    A.TinhTien(a, b).Xuat();
    cout << endl;

    cout << "Nhap goc quay: ";
    cin >> rad;
    A.Quay(rad).Xuat();
    cout << endl;

    cout << "Nhap do thu phong k: ";
    cin >> k;
    A.ThuPhong(k).Xuat();

    return 0;
}
