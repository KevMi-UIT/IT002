#include "CTime.h"
#include "CTimeSpan.h"
#include <iostream>

using namespace std;
int main()
{
	CTime time1, time2;
	int sogiay;

	cout << "Nhap Time 1: " << endl;
	cin >> time1;
	cout << "Nhap Time 2" << endl;
	cin >> time2;

	cout << endl;

	cout << "Nhap so giay de cong voi Time 1: ";
	cin >> sogiay;
	cout << "Time 1 sau khi cong voi " << sogiay << " giay: " << time1 + sogiay << endl;

	cout << "Nhap so giay de tru voi Time 2: ";
	cin >> sogiay;
	cout << "Time 2 sau khi tru voi " << sogiay << " giay: " << time2 - sogiay << endl;

	cout << "Time 1 - Time 2 duoc 1 CTimeSpan = " << time1 - time2 << endl;

	cout << "Time 1 them 1 giay = " << ++time1 << endl;
	cout << "Time 2 bot 1 giay = " << --time2 << endl;

	return 0;
}
