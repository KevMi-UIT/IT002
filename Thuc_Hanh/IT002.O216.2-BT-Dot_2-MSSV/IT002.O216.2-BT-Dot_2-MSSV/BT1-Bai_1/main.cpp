#include "CTimeSpan.h"
#include <iostream>
using namespace std;

int main()
{
    CTimeSpan a, b;
    cout << "Nhap CTimeSpan a:" << endl;
    cin >> a;
    cout << "Nhap CTimeSpan b:" << endl;
    cin >> b;

    cout << "a + b: " << (a + b) << endl;

    cout << "a - b: " << (a - b) << endl;

    cout << "a == b: " << (a == b) << endl;

    cout << "a != b: " << (a != b) << endl;

    cout << "a < b: " << (a < b) << endl;

    cout << "a <= b: " << (a <= b) << endl;

    cout << "a > b: " << (a > b) << endl;

    cout << "a >= b: " << (a >= b) << endl;

    return 0;
}
