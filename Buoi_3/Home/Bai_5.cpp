/* Test sample
Nguyen Van A
1234
nam
2005
9.9
Le Van B
6789
nu
2000
9.99
*/
#include <iostream>
using namespace std;

class cHocSinh
{
private:
    int ma;
    string Hoten;
    string gioiTinh;
    int nam;
    double diemTrungBinh;

public:
    cHocSinh();
    void Nhap();
    double getDiemTB() const;
    int getNam() const;
    string getTen() const;
    static void DiemCao(const cHocSinh &, const cHocSinh &);
    static void NhoTuoi(const cHocSinh &, const cHocSinh &);
};

int main()
{
    cHocSinh hs1, hs2;
    hs1.Nhap();
    hs2.Nhap();
    cHocSinh::DiemCao(hs1, hs2);
    cHocSinh::NhoTuoi(hs1, hs2);
    return 0;
}

cHocSinh::cHocSinh()
{
    this->ma = 0;
    this->Hoten = "";
    this->gioiTinh = "";
    this->nam = 0;
    this->diemTrungBinh = 0;
}

void cHocSinh::Nhap()
{
    cout << "Nhap ho ten hoc sinh: ";
    getline(cin, this->Hoten);

    cout << "Nhap ma hoc sinh: ";
    cin >> this->ma;

    cout << "Nhap gioi tinh: ";
    cin >> this->gioiTinh;

    cout << "Nhap nam sinh: ";
    cin >> this->nam;

    cout << "Nhap diem trung binh: ";
    cin >> this->diemTrungBinh;
    cin.ignore();
}

double cHocSinh ::getDiemTB() const
{
    return this->diemTrungBinh;
}

int cHocSinh::getNam() const
{
    return this->nam;
}

string cHocSinh::getTen() const
{
    return this->Hoten;
}

void cHocSinh::DiemCao(const cHocSinh &hs1, const cHocSinh &hs2)
{
    if (hs1.getDiemTB() > hs2.getDiemTB())
        cout << "Hoc sinh cao diem hon la " << hs1.getTen();
    else if (hs1.getDiemTB() < hs2.getDiemTB())
        cout << "Hoc sinh cao diem hon la " << hs2.getTen();
    else
        cout << "Hai hoc sinh bang diem nhau";
    cout << endl;
}

void cHocSinh::NhoTuoi(const cHocSinh &hs1, const cHocSinh &hs2)
{
    if (hs1.getNam() > hs2.getNam())
        cout << "Hoc sinh nho tuoi hon la " << hs1.getTen();
    else if (hs1.getNam() < hs2.getNam())
        cout << "Hoc sinh nho tuoi hon la " << hs2.getTen();
    else
        cout << "Hai hoc sinh bang tuoi nhau";
    cout << endl;
}
