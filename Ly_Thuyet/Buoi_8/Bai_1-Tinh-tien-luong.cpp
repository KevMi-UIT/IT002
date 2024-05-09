#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhanVien
{
  protected:
    string hoTen;
    int ngaySinh, thangSinh, namSinh;
    long luongCoBan;

  public:
    NhanVien()
    {
        hoTen = "";
        ngaySinh = 0;
        thangSinh = 0;
        namSinh = 0;
        luongCoBan = 0;
    }
    NhanVien(string _HoTen, int _Ngay, int _Thang, int _Nam, long _Luong)
        : hoTen(_HoTen), ngaySinh(_Ngay), thangSinh(_Thang), namSinh(_Nam), luongCoBan(_Luong)
    {
    }

    virtual void print(ostream &out) const;
    friend istream &operator>>(istream &, NhanVien &);
    friend ostream &operator<<(ostream &, const NhanVien &);
};

class NhanVienVanPhong : public NhanVien
{
    int soNgayLamViec;
    long troCap;
    long Luong = luongCoBan + 200000 * soNgayLamViec + troCap;

  public:
    NhanVienVanPhong() : NhanVien("", 0, 0, 0, 0)
    {
    }
    NhanVienVanPhong(string ht, int ng, int th, int nam, long Luong, int _soNgayLam, long _troCap)
        : NhanVien(ht, ng, th, nam, Luong)
    {
        soNgayLamViec = _soNgayLam;
        troCap = _troCap;
    }
    friend istream &operator>>(istream &, NhanVienVanPhong &);
    friend ostream &operator<<(ostream &, const NhanVienVanPhong &);
};

class NhanVienSanXuat : public NhanVien
{
    int soSanPham;
    long Luong = luongCoBan + 2000 * soSanPham;

  public:
    NhanVienSanXuat() : NhanVien("", 0, 0, 0, 0)
    {
    }
    NhanVienSanXuat(string ht, int ng, int th, int nam, long Luong, int _soSanPham) : NhanVien(ht, ng, th, nam, Luong)
    {
        soSanPham = _soSanPham;
    }
    friend istream &operator>>(istream &, NhanVienSanXuat &);
    friend ostream &operator<<(ostream &, const NhanVienSanXuat &);
};

class NhanVienQuanLy : public NhanVien
{
    int heSoChucVu;
    long tienThuong;
    long Luong = luongCoBan * heSoChucVu + tienThuong;

  public:
    NhanVienQuanLy() : NhanVien("", 0, 0, 0, 0)
    {
    }
    NhanVienQuanLy(string ht, int ng, int th, int nam, long Luong, int heso, long thuong)
        : NhanVien(ht, ng, th, nam, Luong)
    {
        heSoChucVu = heso;
        tienThuong = thuong;
    }
    friend istream &operator>>(istream &, NhanVienQuanLy &);
    friend ostream &operator<<(ostream &, const NhanVienQuanLy &);
};

class DanhSachNhanVien
{
  private:
    int soLuong;
    vector<NhanVien *> ds;

  public:
    void input(istream &);
    void output(ostream &);
    friend istream &operator>>(istream &, DanhSachNhanVien &);
    friend ostream &operator<<(ostream &, const DanhSachNhanVien &);
    long long tongLuong;
};
istream &operator>>(istream &in, NhanVien &nv)
{
    cout << "Nhap ten: ";
    getline(in, nv.hoTen);
    in.ignore();
    return in;
}

void NhanVien::print(ostream &out) const
{
    out << "Ho ten: " << this->hoTen << endl;
    out << "Ngay sinh: " << this->ngaySinh << "/" << this->thangSinh << "/" << this->namSinh << endl;
}

ostream &operator<<(ostream &out, const NhanVien &nv)
{
    nv.print(out);
    return out;
}

istream &operator>>(istream &in, NhanVienVanPhong &nvvp)
{
    in >> (NhanVien &)nvvp;
    cout << "Nhap so ngay lam viec: ";
    in >> nvvp.soNgayLamViec;
    cout << "Nhap tro cap: ";
    in >> nvvp.troCap;
    return in;
}

ostream &operator<<(ostream &out, const NhanVienVanPhong &nvvp)
{
    out << (NhanVien &)nvvp;
    out << "Luong cua nhan vien: " << nvvp.Luong << " dong" << endl;
    return out;
}

istream &operator>>(istream &in, NhanVienSanXuat &nvsx)
{
    in >> (NhanVien &)nvsx;
    cout << "Nhap so san pham: ";
    in >> nvsx.soSanPham;
    return in;
}

ostream &operator<<(ostream &out, const NhanVienSanXuat &nvsx)
{
    out << (NhanVien &)nvsx;
    out << "Luong cua nhan vien: " << nvsx.Luong << " dong" << endl;
    return out;
}

istream &operator>>(istream &in, NhanVienQuanLy &nvql)
{
    in >> (NhanVien &)nvql;
    cout << "Nhap he so chuc vu: ";
    in >> nvql.heSoChucVu;
    cout << "Nhap luong thuong: ";
    in >> nvql.tienThuong;
    return in;
}

ostream &operator<<(ostream &out, const NhanVienQuanLy &nvql)
{
    out << (NhanVien &)nvql;
    out << "Luong cua quan ly: " << nvql.Luong << " dong" << endl;
    return out;
}

void DanhSachNhanVien::input(istream &in)
{
    int opt, size;
    cout << "Nhap so luong nhan vien: " << endl;
    cin >> this->soLuong;
    for (int i = 0; i < this->soLuong; ++i)
    {
        cout << endl;
        cout << "------Nhap nguoi thu " << i + 1 << "------" << endl;
        cout << "[1]:Nhan Vien Van Phong" << '\n'
             << "[2]:Nhan Vien San Xuat" << '\n'
             << "[3]:Nhan Vien Quan Ly" << '\n';
        cout << "----------------------------" << endl;
        do
        {
            cout << "Nhap lua chon: " << endl;
            cin >> opt;
            switch (opt)
            {
            case 1:
                NhanVienVanPhong *nvvp = new NhanVienVanPhong;
                cin >> (*nvvp);
                ds.push_back(nvvp);
                break;
            case 2:
                NhanVienSanXuat *nvsx = new NhanVienSanXuat;
                cin >> (*nvsx);
                ds.push_back(nvsx);
                break;
            case 3:
                NhanVienQuanLy *nvql = new NhanVienQuanLy;
                cin >> (*nvql);
                ds.push_back(nvql);
                break;
            default:
                break;
            }
        } while (opt < 1 || opt > 3);
    }
}

istream &operator>>(istream &in, DanhSachNhanVien &list)
{
    list.input(in);
    return in;
}

void DanhSachNhanVien::output(ostream &out)
{
}
