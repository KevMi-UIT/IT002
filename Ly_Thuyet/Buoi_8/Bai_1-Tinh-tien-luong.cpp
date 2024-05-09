<<<<<<< HEAD
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
=======
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
    NhanVien(const string &_hoTen = "", const int &_ngay = 0, const int &_thang = 0, const int &_nam = 0,
             const long &_luong = 0)
        : hoTen(_hoTen), ngaySinh(_ngay), thangSinh(_thang), namSinh(_nam), luongCoBan(_luong)
    {
    }
    string getTen() const;
    virtual long getLuong() const;

    void nhap();
    virtual void xuat() const;
};

class NhanVienVanPhong : public NhanVien
{
    int soNgayLamViec;
    long troCap;

  public:
    NhanVienVanPhong(const string &_hoTen = "", const int &_ngay = 0, const int &_thang = 0, const int &_nam = 0,
                     const long &_luong = 0, const int &_soNgayLam = 0, const long &_troCap = 0)
        : NhanVien(_hoTen, _ngay, _thang, _nam, _luong), soNgayLamViec(_soNgayLam), troCap(_troCap)
    {
    }
    void xuat() const;
    void nhap();
    long getLuong() const;
};

class NhanVienSanXuat : public NhanVien
{
    int soSanPham;

  public:
    NhanVienSanXuat(const string &_hoTen = "", const int &_ngay = 0, const int &_thang = 0, const int &_nam = 0,
                    const long &_luong = 0, const int &_soSanPham = 0)
        : NhanVien(_hoTen, _ngay, _thang, _nam, _luong), soSanPham(_soSanPham)
    {
    }
    void xuat() const;
    void nhap();
    long getLuong() const;
};

class NhanVienQuanLy : public NhanVien
{
    int heSoChucVu;
    long tienThuong;

  public:
    NhanVienQuanLy(const string &_hoTen = "", const int &_ngay = 0, const int &_thang = 0, const int &_nam = 0,
                   const long &_luong = 0, const int &_heSo = 0, const long &_thuong = 0)
        : NhanVien(_hoTen, _ngay, _thang, _nam, _luong), heSoChucVu(_heSo), tienThuong(_thuong)
    {
    }
    void xuat() const;
    void nhap();
    long getLuong() const;
};

class DanhSachNhanVien
{
  private:
    int soLuong;
    vector<NhanVien *> ds;

  public:
    void nhap();
    void xuat();
    long long tongLuong = 0;
};

int main()
{
    DanhSachNhanVien list;
    list.nhap();
    list.xuat();
    return 0;
}

string NhanVien::getTen() const
{
    return this->hoTen;
}

long NhanVien::getLuong() const
{
    return this->luongCoBan;
}

void NhanVien::nhap()
{
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, this->hoTen);
    cout << "Nhap ngay sinh: ";
    cin >> this->ngaySinh;
    cout << "Nhap thang sinh: ";
    cin >> this->thangSinh;
    cout << "Nhap nnam sinh: ";
    cin >> this->namSinh;
    cout << "Nhap luong co ban: ";
    cin >> this->luongCoBan;
}

void NhanVien::xuat() const
{
    cout << "Ho ten: " << this->hoTen << endl;
    cout << "Ngay thang nam sinh: " << this->ngaySinh << "/" << this->thangSinh << "/" << this->namSinh << endl;
}

void NhanVienVanPhong::nhap()
{
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> this->soNgayLamViec;
    cout << "Nhap tro cap: ";
    cin >> this->troCap;
}

void NhanVienVanPhong::xuat() const
{
    NhanVien::xuat();
    cout << "Luong cua nhan vien van phong: " << this->getLuong() << " (dong)" << endl;
}

long NhanVienVanPhong::getLuong() const
{
    return this->luongCoBan + 200000 * this->soNgayLamViec + this->troCap;
};

void NhanVienSanXuat::nhap()
{
    NhanVien::nhap();
    cout << "Nhap so san pham: ";
    cin >> this->soSanPham;
}

void NhanVienSanXuat::xuat() const
{
    NhanVien::xuat();
    cout << "Luong cua nhan vien san xuat: " << this->getLuong() << " (dong)" << endl;
}

long NhanVienSanXuat::getLuong() const
{
    return this->luongCoBan + 2000 * this->soSanPham;
};

void NhanVienQuanLy::nhap()
{
    NhanVien::nhap();
    cout << "Nhap he so chuc vu: ";
    cin >> this->heSoChucVu;
    cout << "Nhap luong thuong: ";
    cin >> this->tienThuong;
}

void NhanVienQuanLy::xuat() const
{
    NhanVien::xuat();
    cout << "Luong cua nhan vien quan ly: " << this->getLuong() << " (dong)" << endl;
}

long NhanVienQuanLy::getLuong() const
{
    return this->luongCoBan * this->heSoChucVu + this->tienThuong;
};

void DanhSachNhanVien::nhap()
{
    int opt, size;
    cout << "Nhap so luong nhan vien: " << endl;
    cin >> this->soLuong;
    for (int i = 0; i < this->soLuong; ++i)
    {
        cout << endl;
        cout << "------Nhap nguoi thu " << i + 1 << "------" << endl;
        cout << "[1]: Nhan Vien Van Phong" << endl;
        cout << "[2]: Nhan Vien San Xuat" << endl;
        cout << "[3]: Nhan Vien Quan Ly" << endl;
        cout << "----------------------------" << endl;
        do
        {
            cout << "Nhap lua chon: " << endl;
            cin >> opt;
            switch (opt)
            {
            case 1: {
                NhanVienVanPhong *nvvp = new NhanVienVanPhong;
                nvvp->nhap();
                ds.push_back(nvvp);
                break;
            }
            case 2: {
                NhanVienSanXuat *nvsx = new NhanVienSanXuat;
                nvsx->nhap();
                ds.push_back(nvsx);
                break;
            }
            case 3: {
                NhanVienQuanLy *nvql = new NhanVienQuanLy;
                nvql->nhap();
                ds.push_back(nvql);
                break;
            }
            default:
                break;
            }
        } while (opt < 1 || opt > 3);
    }
}

void DanhSachNhanVien::xuat()
{
    int opt;
    cout << "----------------------------" << endl;
    cout << "[1]: Xuat danh sach nhan vien" << endl;
    cout << "[2]: Tim kiem thong tin nhan vien" << endl;
    cout << "----------------------------" << endl;
    int i = 1;
    do
    {
        cout << "Nhap lua chon: " << endl;
        cin >> opt;
        cin.ignore();
        switch (opt)
        {
        case 1:
            cout << "------- DANH SACH ----------" << endl;
            cout << "So luong nguoi trong danh sach: " << soLuong << endl;
            for (NhanVien *nv : ds)
            {
                this->tongLuong += nv->getLuong();
                cout << i << ".";
                nv->xuat();
                cout << endl;
                cout << "----------------------------" << endl;
                i++;
            }
            cout << "Tong luong cua cong ty: " << this->tongLuong << " (dong)" << endl;
            break;
        case 2: {
            cout << "Nhap ten nhan vien: ";
            string ten;
            getline(cin, ten);
            bool search = false;
            for (NhanVien *nv : ds)
            {
                if (nv->getTen() == ten)
                {
                    nv->xuat();
                    search = true;
                }
            }
            if (!search)
                cout << "Khong tim thay nhan vien" << endl;
            break;
        }
        }
    } while (opt != 1 && opt != 2);
}
>>>>>>> c64f07068610dc96a85f0a5df4a532b3e07d6e85
