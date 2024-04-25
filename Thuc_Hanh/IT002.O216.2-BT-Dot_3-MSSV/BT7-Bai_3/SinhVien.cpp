#include "Nguoi.h"
#include "SinhVien.h"
#include <iostream>
using namespace std;

void SinhVien::Nhap()
{
    Nguoi::Nhap();
    cout << "Ma so sinh vien: ";
    cin >> MSSV;
}
void SinhVien::Xuat() const
{
    Nguoi::Xuat();
    cout << "Nghe nghiep: Sinh Vien" << endl;
    cout << "Ma so sinh vien: " << MSSV;
}
