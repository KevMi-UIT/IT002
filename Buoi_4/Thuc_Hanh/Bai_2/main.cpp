#include "phanso.h"
#include <iostream>
using namespace std;

int main()
{
    PhanSo ps1, ps2, ps3;
    ps1.Nhap();
    ps2.Nhap();
    PhanSo::Max(ps1, ps2, ps3);
    if (ps3.getTu() > 0)
    {
        ps1.Xuat();
    }
    else
    {
        ps2.Xuat();
    }
    return 0;
}
