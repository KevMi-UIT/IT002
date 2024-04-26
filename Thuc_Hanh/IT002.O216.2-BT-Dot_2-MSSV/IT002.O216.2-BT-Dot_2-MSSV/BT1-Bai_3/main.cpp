#include "CDate.h"
#include <iostream>
using namespace std;

int main()
{
    CDate day1, day2;
    int x, y;

    cout << "Nhap ngay thu 1: " << endl;
    day1.Nhap();
    day1.Xuat();

    cout << "Ngay tiep theo cua ngay thu 1: ";
    day1.Them1ngay().Xuat();

    cout << "Ngay truoc do cua ngay thu 1: ";
    day1.Bot1ngay().Xuat();

    cout << "Nhap so ngay cong them cho ngay thu 1: ";
    cin >> x;

    cout << "Ngay thu 1 sau khi cong them: ";
    day1.Cong(x).Xuat();

    cout << "Nhap so ngay tru di cho ngay thu 1: ";
    cin >> y;

    cout << "Ngay thu 1 sau khi tru di: ";
    day1.Tru(y).Xuat();

    cout << "Nhap ngay thu 2: " << endl;
    day2.Nhap();
    day2.Xuat();

    cout << "Khoang cach giua 2 ngay: ";
    cout << day1.KhoangCach(day2) << " ngay" << endl;
    return 0;
}
