#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhanVien
{
  protected:
    int maNv;
    int Tuoi;
    int Sdt;
    int luongCoBan;
    string Email;
    string Ten;

  public:
    virtual int tinhLuong() const = 0; // Phương thức ảo tính lương
    friend istream &operator>>(istream &, NhanVien &);
    friend ostream &operator<<(ostream &, const NhanVien &);
};

class LapTrinhVien : public NhanVien
{
  private:
    unsigned int soGioOT;

  public:
    LapTrinhVien(const unsigned int &insoGioOT = 0) : soGioOT(insoGioOT)
    {
    }
    int tinhLuong() const override
    {
        return luongCoBan + soGioOT * 200000;
    }
    friend istream &operator>>(istream &, LapTrinhVien &);
    friend ostream &operator<<(ostream &, const LapTrinhVien &);
};

class KiemChungVien : public NhanVien
{
  private:
    unsigned int soLoi;

  public:
    KiemChungVien(const unsigned int &insoLoi = 0) : soLoi(insoLoi)
    {
    }
    int tinhLuong() const override
    {
        return luongCoBan + soLoi * 50000;
    }
    friend istream &operator>>(istream &, KiemChungVien &);
    friend ostream &operator<<(ostream &, const KiemChungVien &);
};

istream &operator>>(istream &is, NhanVien &nv)
{
    cout << "Nhap ma nhan vien: ";
    is >> nv.maNv;
    cout << "Nhap ten: ";
    is >> nv.Ten;
    cout << "Nhap tuoi: ";
    is >> nv.Tuoi;
    cout << "Nhap so dien thoai: ";
    is >> nv.Sdt;
    cout << "Nhap email: ";
    is >> nv.Email;
    cout << "Nhap luong co ban: ";
    is >> nv.luongCoBan;
    return is;
}

ostream &operator<<(ostream &os, const NhanVien &nv)
{
    os << "Ma nhan vien: " << nv.maNv << endl;
    os << "Ten: " << nv.Ten << endl;
    os << "Tuoi: " << nv.Tuoi << endl;
    os << "So dien thoai: " << nv.Sdt << endl;
    os << "Email: " << nv.Email << endl;
    os << "Luong co ban: " << nv.luongCoBan << endl;
    return os;
}

istream &operator>>(istream &is, LapTrinhVien &ltv)
{
    is >> static_cast<NhanVien &>(ltv); // Nhập thông tin chung
    cout << "Nhap so gio overtime: ";
    is >> ltv.soGioOT;
    return is;
}

ostream &operator<<(ostream &os, const LapTrinhVien &ltv)
{
    os << static_cast<const NhanVien &>(ltv); // Xuất thông tin chung
    os << "So gio overtime: " << ltv.soGioOT << endl;
    return os;
}

istream &operator>>(istream &is, KiemChungVien &kcv)
{
    is >> static_cast<NhanVien &>(kcv); // Nhập thông tin chung
    cout << "Nhap so loi phat hien: ";
    is >> kcv.soLoi;
    return is;
}

ostream &operator<<(ostream &os, const KiemChungVien &kcv)
{
    os << static_cast<const NhanVien &>(kcv); // Xuất thông tin chung
    os << "So loi phat hien: " << kcv.soLoi << endl;
    return os;
}

void lietKeNhanVienLuongThap(const vector<NhanVien *> &danhSachNhanVien)
{
    int tongLuong = 0;
    for (const auto &nv : danhSachNhanVien)
    {
        tongLuong += nv->tinhLuong(); // Sử dụng phương thức ảo tính lương
    }
    double luongTrungBinh = static_cast<double>(tongLuong) / danhSachNhanVien.size();

    cout << "Nhan vien co luong thap hon muc luong trung binh (" << luongTrungBinh << "):\n";
    for (const auto &nv : danhSachNhanVien)
    {
        if (nv->tinhLuong() < luongTrungBinh)
        {
            cout << *nv << endl;
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;

    vector<NhanVien *> danhSachNhanVien;

    for (int i = 0; i < n; ++i)
    {
        bool isLapTrinhVien;
        cout << "Nhap loai nhan vien (1: Lap trinh vien, 0: Kiem chung vien): ";
        cin >> isLapTrinhVien;

        if (isLapTrinhVien)
        {
            LapTrinhVien *ltv = new LapTrinhVien();
            cin >> *ltv; // Nhập thông tin cho lập trình viên
            danhSachNhanVien.push_back(ltv);
        }
        else
        {
            KiemChungVien *kcv = new KiemChungVien();
            cin >> *kcv; // Nhập thông tin cho kiểm chứng viên
            danhSachNhanVien.push_back(kcv);
        }
    }

    for (const auto &nv : danhSachNhanVien)
    {
        cout << *nv << endl; // Xuất thông tin của từng nhân viên
    }

    lietKeNhanVienLuongThap(danhSachNhanVien); // Liệt kê nhân viên có lương thấp hơn trung bình

    // Giải phóng bộ nhớ
    for (auto &nv : danhSachNhanVien)
    {
        delete nv;
    }

    return 0;
}
