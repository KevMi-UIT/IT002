#include "CTime.h"
#include "CTimeSpan.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    CTime Time, Time1;
    CTime PhepCong, PhepTru, CongMotGiay, TruMotGiay;
    CTimeSpan Result;
    int sogiay;
    cout << "Nhap so giay: ";
    cin >> sogiay;
    cout << "Nhap Time" << endl;
    cin >> Time;
    cout << "Nhap Time 1" << endl;
    cin >> Time1;
    cout << "Thoi gian da nhap " << endl;
    cout << Time << endl;
    cout << "Sau khi cong so giay " << endl;
    PhepCong = Time + sogiay;
    cout << PhepCong << endl;
    cout << "Sau khi tru so giay " << endl;
    PhepTru = Time - sogiay;
    cout << PhepTru << endl;
    cout << "Sau khi cong mot giay " << endl;
    CongMotGiay = ++Time;
    cout << CongMotGiay << endl;
    cout << "Sau khi tru mot giay " << endl;
    TruMotGiay = --Time;
    cout << TruMotGiay << endl;
    Result = Time.TruCTS(Time1);
    cout << "CTimeSpan Time - Time1: ";
    cout << Result << endl;
    return 0;
}
