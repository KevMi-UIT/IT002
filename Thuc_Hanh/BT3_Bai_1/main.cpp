#include "Diem.h"
#include <iostream>
using namespace std;

int main()
{
    Diem A;
    float a, b, c, d;

    A.Nhap();
    A.Xuat();

    cout << "Thay doi toa do cua diem." << endl;
    cout << "Thay doi hoanh do: x= ";
    cin >> c;
    A.setX(c);

    cout << "Thay doi tung do: y= ";
    cin >> d;
    A.setY(d);

    cout << "Hoanh do cua diem: x= ";
    cout << A.getX() << endl;

    cout << "Tung do cua diem: y= ";
    cout << A.getY() << endl;

    cout << "Nhap toa do tinh tien: ";
    cin >> a >> b;
    A.TinhTien(a, b).Xuat();
    cout << endl;

    return 0;
}
