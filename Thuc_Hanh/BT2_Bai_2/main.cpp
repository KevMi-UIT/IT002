#include "ComplexNum.h"
#include <iostream>
using namespace std;

int main()
{
    ComplexNum num1, num2;
    cout << "Nhap so phuc 1: " << endl;
    cin >> num1;
    cout << "Nhap so phuc 2: " << endl;
    cin >> num2;
    cout << "So phuc 1: " << num1 << endl;
    cout << "So phuc 2: " << num2 << endl;
    cout << "So phuc 1 + So phuc 2: " << num1 + num2 << endl;
    cout << "So phuc 1 - So phuc 2: " << num1 - num2 << endl;
    cout << "So phuc 1 * So phuc 2: " << num1 * num2 << endl;
    cout << "So phuc 1 / So phuc 2: " << num1 / num2 << endl;
    return 0;
}
