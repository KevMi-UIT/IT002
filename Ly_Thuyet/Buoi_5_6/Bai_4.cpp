#include <iostream>
#include <stdlib.h>
using namespace std;
class Matran
{
  private:
    int m;
    int n;
    int mtr[100][100];

  public:
    void ran_Xuat_Nhap();
    void Nhap();
    void Xuat();
    Matran operator+(const Matran &);
    Matran operator-(const Matran &);
};
int main()
{
    Matran a, b, c, d, r;
    a.Nhap();
    b.Nhap();
    r.ran_Xuat_Nhap();
    cout << "Ma tra A la: " << endl;
    a.Xuat();
    cout << "Ma tran B la: " << endl;
    b.Xuat();
    c = a + b;
    c.Xuat();
    d = a - b;
    d.Xuat();
}
void Matran::ran_Xuat_Nhap()
{
    srand(time(NULL));
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            mtr[i][j] = rand() % 100;
        }
    }
    cout << "Ma tran ngau nhien:" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << mtr[i][j] << " ";
        }
        cout << endl;
    }
}
void Matran::Nhap()
{
    cout << "Nhap so dong: ";
    cin >> this->m;
    cout << "Nhap so cot: ";
    cin >> this->n;
    for (int i = 0; i < this->m; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            cin >> mtr[i][j];
        }
    }
}
void Matran::Xuat()
{
    for (int i = 0; i < this->m; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            cout << this->mtr[i][j] << " ";
        }
        cout << endl;
    }
}
Matran Matran::operator+(const Matran &other)
{
    Matran result;
    if (this->m != other.m || this->n != other.n)
    {
        cout << "Khong the cong 2 ma tran " << endl;
        return result;
    }
    else
    {
        cout << "Cong 2 ma tran: " << endl;
        result.m = this->m;
        result.n = this->n;
        for (int i = 0; i < this->m; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                result.mtr[i][j] = this->mtr[i][j] + other.mtr[i][j];
            }
        }
    }
    return result;
}

Matran Matran::operator-(const Matran &other)
{
    Matran result;
    if (this->m != other.m || this->n != other.n)
    {
        cout << "Khong the tru 2 ma tran " << endl;
        return result;
    }
    else
    {
        cout << "Tru 2 ma tran: " << endl;
        result.m = this->m;
        result.n = this->n;
        for (int i = 0; i < this->m; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                result.mtr[i][j] = this->mtr[i][j] - other.mtr[i][j];
            }
        }
    }
    return result;
}