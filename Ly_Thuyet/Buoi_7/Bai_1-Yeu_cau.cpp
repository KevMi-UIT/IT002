#include <cstring>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class CanBoVienChuc
{
  protected:
    string maCanBo;
    string hoTen;
    bool gioiTinh;
    long long luong;

  public:
    CanBoVienChuc(const string &inMaCanBo = "", const string &inHoTen = "", const bool &inGioiTinh = 0)
        : maCanBo(inMaCanBo), hoTen(inHoTen), gioiTinh(inGioiTinh), luong(0)
    {
    }
    friend istream &operator>>(istream &, CanBoVienChuc &);
    friend ostream &operator<<(ostream &, const CanBoVienChuc &);
};

class GiangVien : public CanBoVienChuc
{
  private:
    unsigned int soGioDay;
    unsigned int soGioNghienCuu;
    unsigned int donGia;

  public:
    GiangVien(const unsigned int &inSoGioDay = 0, const unsigned int &inSoGioNghienCuu = 0,
              const unsigned int &inDonGia = 0)
        : soGioDay(inSoGioDay), soGioNghienCuu(inSoGioNghienCuu), donGia(inDonGia)
    {
        setLuong();
    }
    void setLuong();
    friend istream &operator>>(istream &, GiangVien &);
    friend ostream &operator<<(ostream &, const GiangVien &);
};

class NhanVienHanhChinh : public CanBoVienChuc
{
  private:
    unsigned int soNgayLamViec;
    unsigned int soGioLamThem;
    unsigned int tienCongMotNgay;
    unsigned int donGia;

  public:
    NhanVienHanhChinh(const unsigned int &inSoGioDay = 0, const unsigned int &inSoGioNghienCuu = 0,
                      const unsigned int &inTienCongMotNgay = 0, const unsigned int &inDonGia = 0)
        : soNgayLamViec(inSoGioDay), soGioLamThem(inSoGioNghienCuu), tienCongMotNgay(inTienCongMotNgay),
          donGia(inDonGia)
    {
        setLuong();
    }
    void setLuong();
    friend istream &operator>>(istream &, NhanVienHanhChinh &);
    friend ostream &operator<<(ostream &, const NhanVienHanhChinh &);
};

int main()
{
    int n;
    bool select; // 0: GiangVien, 1: NhanVienHanhChinh
    cout << "Nhap so can bo: ";
    cin >> n;
    while (n--)
    {
        cout << "Nhap loai can bo (GiangVien: 0, NhanVienHanhChinh: 1): ";
        cin >> select;
        if (select)
        {
            NhanVienHanhChinh nhanVienHanhChinh;
            cin >> nhanVienHanhChinh;
            cout << nhanVienHanhChinh;
        }
        else
        {
            GiangVien giangVien;
            cin >> giangVien;
            cout << giangVien;
        }
    }
    return 0;
}

void GiangVien::setLuong()
{
    this->luong = (this->soGioDay + this->soGioNghienCuu) * this->donGia;
}

void NhanVienHanhChinh::setLuong()
{
    this->luong = this->soNgayLamViec * this->tienCongMotNgay + this->soGioLamThem * this->donGia;
}

istream &operator>>(istream &is, CanBoVienChuc &canBoVienChuc)
{
    cout << "Nhap ma can bo: ";
    getline(is, canBoVienChuc.maCanBo);
    cout << "Nhap ho ten: ";
    getline(is, canBoVienChuc.hoTen);
    cout << "Nhap gioi tinh (nam = 1, nu = 0): ";
    is >> canBoVienChuc.gioiTinh;
    cout << "Nhap luong: ";
    is >> canBoVienChuc.luong;
    return is;
}

ostream &operator<<(ostream &os, const CanBoVienChuc &canBoVienChuc)
{
    os << "Ma can bo: " << canBoVienChuc.maCanBo << "\n";
    os << "Ho ten: " << canBoVienChuc.hoTen << "\n";
    if (canBoVienChuc.gioiTinh)
        os << "Gioi tinh: Nam\n";
    else
        os << "Gioi tinh: Nu\n";
    os << "Luong: " << canBoVienChuc.luong << "\n";
    return os;
}

istream &operator>>(istream &is, GiangVien &giangVien)
{
    CanBoVienChuc::operator>>(is, giangVien);
    cout << "Nhap so gio day: ";
    is >> giangVien.soGioDay;
    cout << "Nhap so gio nghien cuu: ";
    is >> giangVien.soGioNghienCuu;
    cout << "Nhap don gia: ";
    is >> giangVien.donGia;
    giangVien.setLuong();
    return is;
}

ostream &operator<<(ostream &os, const GiangVien &giangVien)
{
    cout << giangVien;
    os << "So gio day: " << giangVien.soGioDay << "\n";
    os << "So gio nghien cuu: " << giangVien.soGioNghienCuu << "\n";
    os << "Don gia: " << giangVien.donGia << "\n";
    os << "Luong: " << giangVien.luong << "\n";
    return os;
}

istream &operator>>(istream &is, NhanVienHanhChinh &nhanVienHanhChinh)
{
    cin >> nhanVienHanhChinh;
    cout << "Nhap so ngay lam viec: ";
    is >> nhanVienHanhChinh.soNgayLamViec;
    cout << "Nhap so gio lam them: ";
    is >> nhanVienHanhChinh.soGioLamThem;
    cout << "Nhap tien cong mot ngay: ";
    is >> nhanVienHanhChinh.tienCongMotNgay;
    cout << "Nhap don gia: ";
    is >> nhanVienHanhChinh.donGia;
    return is;
}
ostream &operator<<(ostream &os, const NhanVienHanhChinh &nhanVienHanhChinh)
{
    cout << nhanVienHanhChinh;
    os << "So ngay lam viec: " << nhanVienHanhChinh.soNgayLamViec << "\n";
    os << "So gio lam them: " << nhanVienHanhChinh.soGioLamThem << "\n";
    os << "Tien cong mot ngay: " << nhanVienHanhChinh.tienCongMotNgay << "\n";
    os << "Don gia: " << nhanVienHanhChinh.donGia << "\n";
    os << "Luong: " << nhanVienHanhChinh.luong << "\n";
    return os;
}
