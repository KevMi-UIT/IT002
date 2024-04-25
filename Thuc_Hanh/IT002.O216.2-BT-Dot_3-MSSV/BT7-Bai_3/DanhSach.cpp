#include "CaSi.h"
#include "CongNhan.h"
#include "DanhSach.h"
#include "HocSinh.h"
#include "NgheSi.h"
#include "Nguoi.h"
#include "SinhVien.h"
#include <iostream>
using namespace std;

void DanhSach::Nhap()
{
    int opts;
    cout << "Nhap so luong nguoi: ";
    cin >> this->soLuong;

    for (int i = 0; i < this->soLuong; ++i)
    {
        cout << endl;
        cout << "------Nhap nguoi thu " << i + 1 << "------" << endl;
        // cout << "---------------------------" << endl;
        cout << "[1]:Sinh Vien" << '\n'
             << "[2]:Hoc Sinh" << '\n'
             << "[3]:Cong Nhan" << '\n'
             << "[4]:Nghe Si" << '\n'
             << "[5]:Ca Si" << '\n';
        cout << "----------------------------" << endl;
        do
        {
            cout << "Nhap lua chon: ";
            cin >> opts;
            cout << endl;
            switch (opts)
            {
            case 1: {
                SinhVien *sv = new SinhVien;
                sv->Nhap();
                list.push_back(sv);
                break;
            }
            case 2: {
                HocSinh *hs = new HocSinh;
                hs->Nhap();
                list.push_back(hs);
                break;
            }
            case 3: {
                CongNhan *cn = new CongNhan;
                cn->Nhap();
                list.push_back(cn);
                break;
            }
            case 4: {
                NgheSi *ns = new NgheSi;
                ns->Nhap();
                list.push_back(ns);
                break;
            }
            case 5: {
                CaSi *cs = new CaSi;
                cs->Nhap();
                list.push_back(cs);
                break;
            }
            default:
                break;
            }
        } while (opts < 1 || opts > 5);
    }
}

void DanhSach::Xuat() const
{
    cout << "--------------------DANH SACH--------------------" << endl;
    cout << "So luong nguoi trong danh sach: " << soLuong << endl;
    int i = 1;
    for (Nguoi *person : list)
    {
        cout << i << ".";
        person->Xuat();
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        i++;
    }
}
