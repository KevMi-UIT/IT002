#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Dathuc
{
  private:
    int somu;
    vector<int> a; // vector cac he so

  public:
    void Nhap();
    void Xuat() const;
    void Gia_tri(int &);
    Dathuc operator+(const Dathuc &);
    Dathuc operator-(const Dathuc &);
    friend istream &operator>>(istream &in, Dathuc &);
    friend ostream &operator<<(ostream &out, Dathuc &);
};
int main()
{
    Dathuc a, b, c, d;
    a.Nhap();
    b.Nhap();
    a.Xuat();
    b.Xuat();
    c = a + b;
    cout << "Tong cua 2 da thuc: ";
    c.Xuat();
    int x;
    cout << "Nhap gia tri cua x: ";
    cin >> x;
    a.Gia_tri(x);
    b.Gia_tri(x);
    c.Gia_tri(x);
}
void Dathuc::Nhap()
{
    cout << "Nhap bac da thuc: ";
    cin >> this->somu;
    a.resize(this->somu);

    for (int i = 0; i <= this->somu; i++)
    {
        cout << "Nhap he so a" << i << ": ";
        cin >> a[i];
    }
}
void Dathuc::Xuat() const
{
    for (int i = this->somu; i >= 0; --i)
    {
        if (a[i] != 0)
        {
            if (i < this->somu)
            {
                cout << " + ";
            }
            cout << a[i];
            if (i > 0)
            {
                if (i == 1)
                {
                    cout << "x";
                }
                else
                {
                    cout << "x^" << i;
                }
            }
        }
    }
    cout << endl;
}
void Dathuc::Gia_tri(int &x)
{
    int result = 0;
    cout << "Gia tri da thuc: ";
    for (int i = 0; i <= this->somu; i++)
    {
        result += a[i] * pow(x, i);
    }
    cout << result;
    cout << endl;
}
Dathuc Dathuc::operator+(const Dathuc &other)
{
    Dathuc result;
    int maxSize = max(this->somu, other.somu);
    result.somu = maxSize;
    result.a.resize(maxSize + 1);

    for (int i = 0; i <= maxSize; ++i)
    {
        int term1 = (i <= this->somu) ? this->a[i] : 0;
        int term2 = (i <= other.somu) ? other.a[i] : 0;
        result.a[i] = term1 + term2;
    }
    return result;
}
