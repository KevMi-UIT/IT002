#include <cstring>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class SinhVien
{
  protected:
    string HoTen;
    string DiaChi;
    int MSSV;
    double DiemTB;
    int TongTinChi;

  public:
    SinhVien(const string &inHoTen = "", const string &inDiaChi = "", double inDiemTB = 0, int inMSSV = 0,
             int inTongTinChi = 0)
        : HoTen(inHoTen), DiaChi(inDiaChi), DiemTB(inDiemTB), MSSV(inMSSV), TongTinChi(inTongTinChi)
    {
    }
    friend istream &operator>>(istream &, SinhVien &);
    friend ostream &operator<<(ostream &, const SinhVien &);
    virtual bool DieuKienTotNghiep() const = 0;
};

class SinhVienDaiHoc : public SinhVien
{
    string TenLuanVan;
    int DiemLuanVan;

  public:
    SinhVienDaiHoc(const string &inTenLuanVan = "", int inDiemLuanVan = 0)
        : SinhVien(), TenLuanVan(inTenLuanVan), DiemLuanVan(inDiemLuanVan)
    {
    }
    // SinhVienDaiHoc(const SinhVien &);
    friend istream &operator>>(istream &, SinhVienDaiHoc &);
    friend ostream &operator<<(ostream &, const SinhVienDaiHoc &);
    bool DieuKienTotNghiep() const
    {
        return (TongTinChi >= 170 && DiemTB >= 5.0 && DiemLuanVan >= 5.0);
    };
};

class SinhVienCaoDang : public SinhVien
{
    int DiemThiTotNghiep;

  public:
    SinhVienCaoDang(int inDiemThiTN = 0) : SinhVien(), DiemThiTotNghiep(inDiemThiTN)
    {
    }
    // SinhVienCaoDang(const SinhVien &);
    friend ostream &operator<<(ostream &, const SinhVienCaoDang &);
    friend istream &operator>>(istream &, SinhVienCaoDang &);
    bool DieuKienTotNghiep() const
    {
        return (TongTinChi >= 120 && DiemTB >= 5.0 && DiemThiTotNghiep >= 5.0);
    };
};

int main()
{
    SinhVienDaiHoc svdh;
    SinhVienCaoDang svcd;
    cout << "Nhap thong tin sinh vien cao dang: " << endl;
    cin >> svcd;
    cout << "Nhap thong tin sinh vien dai hoc: " << endl;
    cin >> svdh;
    cout << svcd << endl;
    if (svcd.DieuKienTotNghiep())
        cout << "Sinh vien du dieu kien tot nghiep" << endl;
    else
        cout << "Sinh vien khong du dieu kien tot nghiep" << endl;
    cout << svdh << endl;
    if (svdh.DieuKienTotNghiep())
        cout << "Sinh vien du dieu kien tot nghiep" << endl;
    else
        cout << "Sinh vien khong du dieu kien tot nghiep" << endl;
    return 0;
}

istream &operator>>(istream &in, SinhVien &sv)
{
    // cout << "Nhap thong tin sinh vien:" << endl;
    cout << "Nhap ho va ten: ";
    getline(in, sv.HoTen);
    cout << "Nhap dia chi: ";
    getline(in, sv.DiaChi);
    cout << "Nhap ma so sinh vien: ";
    in >> sv.MSSV;
    cout << "Nhap diem trung binh: ";
    in >> sv.DiemTB;
    cout << "Nhap tong so tin chi: ";
    in >> sv.TongTinChi;
    return in;
}

ostream &operator<<(ostream &out, const SinhVien &sv)
{
    out << "-----Thong tin sinh vien-----" << endl;
    out << "Ho va ten: " << sv.HoTen << endl;
    out << "Dia chi: " << sv.DiaChi << endl;
    out << "Ma so sinh vien: " << sv.MSSV << endl;
    out << "Diem trung binh: " << sv.DiemTB << endl;
    out << "Tong so tin chi: " << sv.TongTinChi << endl;
    return out;
}

istream &operator>>(istream &in, SinhVienCaoDang &svcd)
{
    SinhVien &SV = svcd;
    in >> SV;
    in.ignore();
    cout << "Nhap diem thi tot nghiep: ";
    in >> svcd.DiemThiTotNghiep;
    return in;
}

ostream &operator<<(ostream &out, const SinhVienCaoDang &svcd)
{
    const SinhVien &SV = svcd;
    out << SV;
    out << "Diem thi tot nghiep: " << svcd.DiemThiTotNghiep;
    return out;
}

istream &operator>>(istream &in, SinhVienDaiHoc &svdh)
{
    in.ignore();
    SinhVien &SV = svdh;
    in >> SV;
    in.ignore();
    cout << "Nhap ten luan van: ";
    getline(in, svdh.TenLuanVan);
    cout << "Nhap diem luan van: ";
    in >> svdh.DiemLuanVan;
    return in;
}

ostream &operator<<(ostream &out, const SinhVienDaiHoc &svdh)
{
    const SinhVien &SV = svdh;
    out << SV;
    out << "Ten luan van: " << svdh.TenLuanVan << endl;
    out << "Diem luan van: " << svdh.DiemLuanVan;
    return out;
}
