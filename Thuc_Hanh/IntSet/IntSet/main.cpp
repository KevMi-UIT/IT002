#include "IntSet.h"
#include <iostream>
using namespace std;

int main()
{
    int *list = new int[3];
    list[0] = 1;
    list[1] = 2;
    list[2] = 2;
    IntSet s1, s2(list, 3), s3;
    cout << "Xuat s2:" << endl;
    cout << s2;
    cin >> s1 >> s2;
    s3 = s1 + s2; // Union
    cout << "Xuat s3 = s1 + s2:" << endl;
    cout << s3;
    s3 = s1 - s2; // S1\S2 diff
    cout << "Xuat s3 = s1 - s2:" << endl;
    cout << s3;
    cout << "Gia tri cua s3[0]: " << s3[0] << endl;
    cout << "s2 == s2: " << (s1 == s2); // kiem tra 2 tap hop giong nhau ko
    return 0;
}
