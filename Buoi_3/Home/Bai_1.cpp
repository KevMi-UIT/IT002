#include <iostream>
#include <cstring>
using namespace std;

class HocSinh
{
private:
    string hoTen;
    float diemToan;
    float diemVan;
    float diemTrungBinh;
    string xepLoai;

public:
    void Nhap();
    void Xuat() const;

private:
    void TinhDiemTrungBinh();
    void XetXepLoai();
};

int main()
{
    return 0;
}

void HocSinh::Nhap()
{
    cout << "Nhap ho ten sinh vien: ";
    getline(cin, this->hoTen);
    cout << "Nhap diem toan: ";
    cin >> this->diemToan;
    cout << "Nhap diem van: ";
    cin >> this->diemVan;
    this->TinhDiemTrungBinh();
    this->XetXepLoai();
}

void HocSinh::TinhDiemTrungBinh()
{
    this->diemTrungBinh = (this->diemToan + this->diemVan) / 2;
}

void HocSinh::XetXepLoai()
{
    if (this->diemTrungBinh >= 8.5)
    {
        this->xepLoai = "Gioi";
    }
    else if (this->diemTrungBinh >= 8)
    {
        this->xepLoai = "Kha gioi";
    }
}