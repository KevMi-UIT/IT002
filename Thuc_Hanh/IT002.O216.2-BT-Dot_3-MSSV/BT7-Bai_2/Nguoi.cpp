#include "Nguoi.h"
#include <iostream>
using namespace std;

void Nguoi::Nhap()
{
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, this->Hoten);
    cout << "Nhap nam sinh: ";
    cin >> this->NamSinh;
    cin.ignore();
}

void Nguoi::Xuat() const
{
    cout << Hoten << endl;
    cout << "Nam sinh: " << NamSinh << endl;
}
