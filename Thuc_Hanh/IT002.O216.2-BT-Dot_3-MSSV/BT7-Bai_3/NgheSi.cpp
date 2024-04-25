#include "NgheSi.h"
#include "Nguoi.h"
#include <iostream>
using namespace std;

void NgheSi::Nhap()
{
    Nguoi::Nhap();
    cout << "Nhap Cat-xe: ";
    cin >> this->CatXe;
    cout << "Nhap tuoi nghe: ";
    cin >> this->TuoiNghe;
}

void NgheSi::Xuat() const
{
    Nguoi::Xuat();
    cout << "Nghe nghiep: Nghe Si" << endl;
    cout << "Cat-xe: " << this->CatXe << " dong" << endl;
    cout << "Tuoi nghe: " << this->TuoiNghe;
}
