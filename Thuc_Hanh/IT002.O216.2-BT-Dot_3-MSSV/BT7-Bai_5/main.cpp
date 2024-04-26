#include "HinhBinhHanh.h"
#include "HinhChuNhat.h"
#include "HinhHoc.h"
#include "HinhThang.h"
#include "HinhVuong.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Quy uoc cac diem d1, d2, d3, d4 lan luot tu cac goc trai tren, phai tren, phai duoi, trai duoi" << endl;
    cout << "Quy uoc:" << endl;
    cout << "\tHinh thang: 1" << endl;
    cout << "\tHinh binh hanh: 2" << endl;
    cout << "\tHinh chu nhat: 3" << endl;
    cout << "\tHinh vuong: 4" << endl;

    int n;
    cout << "Nhap loai hinh hoc: ";
    cin >> n;

    HinhHoc *shape = NULL;

    switch (n)
    {
    case 1:
        shape = new HinhThang();
        break;
    case 2:
        shape = new HinhBinhHanh();
        break;
    case 3:
        shape = new HinhChuNhat();
        break;
    case 4:
        shape = new HinhVuong();
        break;
    default:
        cout << "Loai hinh hoc khong hop le!" << endl;
    }

    if (shape)
    {
        shape->Nhap();
        shape->Xuat();
        delete shape;
    }

    return 0;
}
