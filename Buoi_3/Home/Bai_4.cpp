#define MAX 200
#define MIN -200

#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

int MAX_WIDTH = to_string(MAX).length() + 3;

class cArray
{
private:
    int n;
    vector<int> v;

public:
    cArray();
    void XuatMang();
    int TimSoAmLonNhat();
    int DemLanXuatHienX(const int &x);
    bool KiemTraGiamDan();
    void SapXepTangDan();
};

int main()
{
    cArray myArray;

    myArray.XuatMang();

    int maxNeg = myArray.TimSoAmLonNhat();
    switch (maxNeg)
    {
    case 0:
        cout << "Khong co so am" << endl;
        break;
    default:
        cout << "So am lon nhat: " << maxNeg << endl;
        break;
    }

    int x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "So lan xuat hien " << x << ": " << myArray.DemLanXuatHienX(x) << endl;

    switch (myArray.KiemTraGiamDan())
    {
    case false:
        cout << "Mang khong phai giam dan" << endl;
        break;
    case true:
        cout << "Mang giam dan" << endl;
        break;
    }

    cout << "Mang sap xep tang dan" << endl;
    myArray.SapXepTangDan();
    myArray.XuatMang();

    return 0;
}

cArray::cArray()
{
    cout << "Nhap n: ";
    cin >> this->n;
    srand(time(NULL));
    this->v.resize(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % (MAX - MIN) - MAX + 1;
}

void cArray::XuatMang()
{
    for (auto it : this->v)
        cout << setw(MAX_WIDTH) << it;
    cout << endl;
}

int cArray::TimSoAmLonNhat()
{
    int res = 0;
    for (auto it : this->v)
        if (it < 0)
            switch (res)
            {
            case 0:
                res = it;
                break;
            default:
                if (it > res)
                    res = it;
                break;
            }
    return res;
}

int cArray::DemLanXuatHienX(const int &x)
{
    int count = 0;
    for (auto it : this->v)
        if (it == x)
            count++;
    return count;
}

bool cArray::KiemTraGiamDan()
{
    for (int i = 0; i < this->n - 1; i++)
        if (v[i] < v[i + 1])
            return false;
    return true;
}

void cArray::SapXepTangDan()
{
    sort(this->v.begin(), this->v.end());
}