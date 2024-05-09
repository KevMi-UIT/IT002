#include "HinhBinhHanh.h"
#include "HinhChuNhat.h"
#include "HinhHoc.h"
#include "HinhThang.h"
#include "HinhVuong.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Quy uoc cac diem d1, d2, d3, d4 lan luot tu cac goc trai tren, phai tren, phai duoi, trai duoi" << endl;
    cout << "Quy uoc:" << endl;
    cout << "\tHinh thang: 1" << endl;
    cout << "\tHinh binh hanh: 2" << endl;
    cout << "\tHinh chu nhat: 3" << endl;
    cout << "\tHinh vuong: 4" << endl;
    cout << endl;

    int n;
    cout << "Nhap so hinh hoc: ";
    cin >> n;
    cout << endl;

    vector<HinhHoc *> ds;
    ds.resize(n);
    int select{0};
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap loai hinh hoc: ";
        cin >> select;
        switch (select)
        {
        case 1: {
            ds[i] = new HinhThang();
            ds[i]->Nhap();
            break;
        }
        case 2: {

            ds[i] = new HinhBinhHanh();
            ds[i]->Nhap();
            break;
        }
        case 3: {

            ds[i] = new HinhChuNhat();
            ds[i]->Nhap();
            break;
        }
        case 4: {
            ds[i] = new HinhVuong();
            ds[i]->Nhap();
            break;
        }
        default: {
            cout << "Loai hinh hoc khong hop le!" << endl;
            cout << "Vui long nhap lai!" << endl;
            --i;
        }
        }
        cout << endl;
    }

    cout << "------------------" << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Hinh thu " << i + 1 << ":" << endl;
        ds[i]->Xuat();
        cout << endl;
    }

    return 0;
}
