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
    HocSinh hs;
    hs.Nhap();
    hs.Xuat();
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

void HocSinh::Xuat() const
{
    cout << "Hoc sinh: " << this->hoTen << endl;
    cout << "Diem trung binh: " << this->diemTrungBinh << endl;
    cout << "Xep loai: " << this->xepLoai << endl;
}

void HocSinh::TinhDiemTrungBinh()
{
    this->diemTrungBinh = (this->diemToan + this->diemVan) / 2;
}

void HocSinh::XetXepLoai()
{
    if (this->diemTrungBinh >= 8.5)
        this->xepLoai = "Gioi";
    else if (this->diemTrungBinh >= 8)
        this->xepLoai = "Kha gioi";
    else if (this->diemTrungBinh >= 7)
        this->xepLoai = "Kha";
    else if (this->diemTrungBinh >= 6.5)
        this->xepLoai = "Trung binh kha";
    else if (this->diemTrungBinh >= 5.5)
        this->xepLoai = "Trung binh";
    else if (this->diemTrungBinh >= 5)
        this->xepLoai = "Trung binh yeu";
    else if (this->diemTrungBinh >= 4)
        this->xepLoai = "Yeu";
    else
        this->xepLoai = "Kem";
}
