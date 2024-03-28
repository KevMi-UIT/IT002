#include <iostream>
using namespace std;

void func(int i, int j = 0)
{
    cout << "So nguyen : " << i << " " << j << endl;
}
void func(float i = 0, float j = 0)
{
    cout << "So thuc : " << i << " " << j << endl;
}
int main()
{
    int i = 1, j = 2;
    float f = 1.5, g = 2.5;
    func();
    func(i);
    func(f);
    func(i, j);
    func(f, g);
    return 0;
}