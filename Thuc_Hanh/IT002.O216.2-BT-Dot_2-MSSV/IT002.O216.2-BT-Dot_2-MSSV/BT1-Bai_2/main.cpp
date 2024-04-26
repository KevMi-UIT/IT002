#include "CTime.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    CTime Time, Time1, Time2;
    int sogiay;
    cout << "Nhap thoi gian" << endl;
    Time.Nhap();
    cout << "Nhap so giay : ";
    cin >> sogiay;
    cout << "Thoi gian sau khi cong them: ";
    Time.Cong(sogiay).Xuat();
    cout << endl;
    cout << "Thoi gian sau khi tru di: ";
    Time.Tru(sogiay).Xuat();
    cout << endl;
    cout << "Ket qua them 1 giay " << endl;
    Time.ThemMotGiay().Xuat();
    cout << endl;
    cout << "Ket qua bot 1 giay " << endl;
    Time.BotMotGiay().Xuat();
    cout << endl;
    cout << "Nhap thoi gian 1 " << endl;
    Time1.Nhap();
    cout << "Nhap thoi gian 2 " << endl;
    Time2.Nhap();
    cout << "Ket qua tru 2 thoi gian " << endl;
    Time1.TruCTS(Time2).Xuat();
}
