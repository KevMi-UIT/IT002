#include "GiaSuc.h"
#include <iostream>
#include <random>
using namespace std;

GiaSuc::GiaSuc(const int &_SoCon, const int &_MaxSoSua)
{
    this->soCon = _SoCon ? _SoCon : this->randomCon();
    this->soSua = this->randomSua(_MaxSoSua);
}

void GiaSuc::Xuat() const
{
    cout << "So con: " << this->soCon << endl;
    cout << "So sua: " << this->soSua << "l" << endl;
}

int GiaSuc::getSoCon() const
{
    return this->soCon;
}

int GiaSuc::getSoSua() const
{
    return this->soSua;
}

string GiaSuc::getLoai() const
{
    return this->loai;
}

int GiaSuc::randomCon()
{
    srand(time(NULL));
    return rand() % (MAX_SO_CON + 1);
}

int GiaSuc::randomSua(const int &maxSua)
{
    srand(time(NULL));
    return rand() % (maxSua + 1);
}
