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
    string getTen()
    {
        return this->hoTen;
    }
    virtual long getLuong() const
    {
        return this->luongCoBan;
    }

    virtual void output() const;
    void input();
};

class NhanVienVanPhong : public NhanVien
{
    int soNgayLamViec;
    long troCap;

  public:
    NhanVienVanPhong() : NhanVien("", 0, 0, 0, 0)
    {
    }
    NhanVienVanPhong(string ht, int ng, int th, int nam, long Luong, int _soNgayLam, long _troCap)
        : NhanVien(ht, ng, th, nam, Luong), soNgayLamViec(_soNgayLam), troCap(_troCap)
    {
    }
    void output() const;
    void input();
    long getLuong() const
    {
        return this->luongCoBan + 200000 * soNgayLamViec + troCap;
    };
};

class NhanVienSanXuat : public NhanVien
{
    int soSanPham;

  public:
    NhanVienSanXuat() : NhanVien("", 0, 0, 0, 0)
    {
    }
    NhanVienSanXuat(string ht, int ng, int th, int nam, long Luong, int _soSanPham)
        : NhanVien(ht, ng, th, nam, Luong), soSanPham(_soSanPham)
    {
    }
    void output() const;
    void input();
    long getLuong() const
    {
        return luongCoBan + 2000 * soSanPham;
    };
};

class NhanVienQuanLy : public NhanVien
{
    int heSoChucVu;
    long tienThuong;

  public:
    NhanVienQuanLy() : NhanVien("", 0, 0, 0, 0)
    {
    }
    NhanVienQuanLy(string ht, int ng, int th, int nam, long Luong, int heso, long thuong)
        : NhanVien(ht, ng, th, nam, Luong), heSoChucVu(heso), tienThuong(thuong)
    {
        ;
    }
    void output() const;
    void input();
    long getLuong() const
    {
        return this->luongCoBan * heSoChucVu + tienThuong;
    };
};

class DanhSachNhanVien
{
  private:
    int soLuong;
    vector<NhanVien *> ds;

  public:
    void input();
    void output();
    long long tongLuong = 0;
};
void NhanVien::input()
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

void NhanVien::output() const
{
    cout << "Ho ten: " << this->hoTen << endl;
    cout << "Ngay sinh: " << this->ngaySinh << "/" << this->thangSinh << "/" << this->namSinh << endl;
}

void NhanVienVanPhong::input()
{
    NhanVien::input();
    cout << "Nhap so ngay lam viec: ";
    cin >> this->soNgayLamViec;
    cout << "Nhap tro cap: ";
    cin >> this->troCap;
}

void NhanVienVanPhong::output() const
{
    NhanVien::output();
    cout << "Luong cua nhan vien van phong: " << this->getLuong() << " dong" << endl;
}

void NhanVienSanXuat::input()
{
    NhanVien::input();
    cout << "Nhap so san pham: ";
    cin >> this->soSanPham;
}

void NhanVienSanXuat::output() const
{
    NhanVien::output();
    cout << "Luong cua nhan vien san xuat: " << this->getLuong() << " dong" << endl;
}

void NhanVienQuanLy::input()
{
    NhanVien::input();
    cout << "Nhap he so chuc vu: ";
    cin >> this->heSoChucVu;
    cout << "Nhap luong thuong: ";
    cin >> this->tienThuong;
}

void NhanVienQuanLy::output() const
{
    NhanVien::output();
    cout << "Luong cua nhan vien quan ly: " << this->getLuong() << " dong" << endl;
}

void DanhSachNhanVien::input()
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
            case 1: {
                NhanVienVanPhong *nvvp = new NhanVienVanPhong;
                nvvp->input();
                ds.push_back(nvvp);
                break;
            }
            case 2: {
                NhanVienSanXuat *nvsx = new NhanVienSanXuat;
                nvsx->input();
                ds.push_back(nvsx);
                break;
            }
            case 3: {
                NhanVienQuanLy *nvql = new NhanVienQuanLy;
                nvql->input();
                ds.push_back(nvql);
                break;
            }
            default:
                break;
            }
        } while (opt < 1 || opt > 3);
    }
}

void DanhSachNhanVien::output()
{
    int opt;
    cout << "-------------------------------------------------" << endl;
    cout << "[1]:Xuat danh sach nhan vien" << '\n' << "[2]:Tim kiem thong tin nhan vien" << '\n';
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
            cout << "--------------------DANH SACH--------------------" << endl;
            cout << "So luong nguoi trong danh sach: " << soLuong << endl;
            for (NhanVien *nv : ds)
            {
                this->tongLuong += nv->getLuong();
                cout << i << ".";
                nv->output();
                cout << endl;
                cout << "-------------------------------------------------" << endl;
                i++;
            }
            cout << "Tong luong cua cong ty: " << this->tongLuong << " dong" << endl;
            break;
        case 2: {
            cout << "Nhap ten nhan vien: ";
            string ten;
            // cin.ignore();
            getline(cin, ten);
            bool search = false;
            for (NhanVien *nv : ds)
            {
                if (nv->getTen() == ten)
                {
                    nv->output();
                    search = true;
                }
            }
            if (!search)
                cout << "Khong tim thay nhan vien." << endl;
            break;
        }
        }
    } while (opt != 1 && opt != 2);
}

int main()
{
    DanhSachNhanVien list;
    list.input();
    list.output();
    return 0;
}
