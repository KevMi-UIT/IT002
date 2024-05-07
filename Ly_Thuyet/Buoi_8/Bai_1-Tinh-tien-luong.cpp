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
