/*
4
001
Tran Binh
A01
12000000
100000
003
Dong Minh Chi
A04
15000000
500000
002
Phan Le Minh
A03
20000000
0
007
Pham Van Teo
A02
500000
20000000
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct NhanVien
{
    char maNhanVien[9];
    char hoTen[20];
    char phongBan[10];
    int luong;
    int thuong;
    int thucLanh;
};
typedef NhanVien NHANVIEN;

struct DanhSach
{
    vector<NHANVIEN> danhSach;
    int soLuong;
};
typedef DanhSach DANHSACH;

void InputNhanVien(NhanVien &);
void XuatNhanVien(const NHANVIEN &);
DANHSACH CreateDanhSachNhanVien();
void XuatDanhSachNhanVien(const DANHSACH &);
long TinhTongThucLanh(const DANHSACH &);
void XuatNhungNhanVienLuongThapNhat(const DANHSACH &);
int DemSoLuongNhanVienThuongTren12tr(const DANHSACH &);
bool NhanVienGreater(const NhanVien &, const NhanVien &);
DANHSACH SortDanhSachNhanVien(const DANHSACH &);

int main()
{
    DANHSACH ds = CreateDanhSachNhanVien();
    // Cau a
    cout << "Tong luong cty phai tra: " << TinhTongThucLanh(ds) << endl;
    cout << endl;
    // Cau b
    XuatNhungNhanVienLuongThapNhat(ds);
    cout << endl;
    // Cau c
    cout << "So nhan vien thuong >= 12tr: " << DemSoLuongNhanVienThuongTren12tr(ds) << endl;
    cout << endl;
    // Cau d
    cout << "In danh sach nhan vien tang dan:" << endl;
    XuatDanhSachNhanVien(SortDanhSachNhanVien(ds));
    return 0;
}

void InputNhanVien(NHANVIEN &nhanVien)
{
    cout << "\tNhap ma nhan vien: ";
    cin >> nhanVien.maNhanVien;
    cin.ignore();
    cout << "\tNhap ho va ten: ";
    cin.get(nhanVien.hoTen, 20, '\n');
    cin.ignore();
    cout << "\tNhap phong ban: ";
    cin.get(nhanVien.phongBan, 10, '\n');
    cin.ignore();
    cout << "\tNhap muc luong: ";
    cin >> nhanVien.luong;
    cout << "\tNhap muc thuong: ";
    cin >> nhanVien.thuong;
    nhanVien.thucLanh = nhanVien.luong + nhanVien.thuong;
}

void XuatNhanVien(const NHANVIEN &nhanVien)
{
    cout << "\tHo va ten: " << nhanVien.hoTen << endl;
    cout << "\tMa nhan vien: " << nhanVien.maNhanVien << endl;
    cout << "\tPhong ban: " << nhanVien.phongBan << endl;
}

DANHSACH CreateDanhSachNhanVien()
{
    DANHSACH ds;
    cout << "Nhap so luong nhan vien: ";
    cin >> ds.soLuong;
    ds.danhSach.resize(ds.soLuong);
    for (int i = 0; i < ds.soLuong; i++)
    {
        cout << "Nhap thong tin cho nhan vien " << i + 1 << ": " << endl;
        InputNhanVien(ds.danhSach[i]);
    }
    return ds;
}

void XuatDanhSachNhanVien(const DANHSACH &ds)
{
    for (int i = 0; i < ds.soLuong; i++)
    {
        cout << "Nhan vien thu " << i << ":" << endl;
        XuatNhanVien(ds.danhSach[i]);
    }
}

long TinhTongThucLanh(const DANHSACH &ds)
{
    long tong = 0;
    for (int i = 0; i < ds.soLuong; i++)
        tong += ds.danhSach[i].luong + ds.danhSach[i].thuong;
    return tong;
}

void XuatNhungNhanVienLuongThapNhat(const DANHSACH &ds)
{
    int min = ds.danhSach[0].luong;
    for (int i = 1; i < ds.soLuong; ++i)
        if (ds.danhSach[i].luong < min)
            min = ds.danhSach[i].luong;
    for (int i = 0; i < ds.soLuong; ++i)
        if (ds.danhSach[i].luong == min)
            cout << "Nhan vien ten \"" << ds.danhSach[i].hoTen << "\" co luong thap nhat" << endl;
}

int DemSoLuongNhanVienThuongTren12tr(const DANHSACH &ds)
{
    int cnt = 0;
    for (int i = 0; i < ds.soLuong; ++i)
        if (ds.danhSach[i].thuong >= 12000000)
            cnt++;
    return cnt;
}

bool NhanVienGreater(const NhanVien &nv1, const NhanVien &nv2)
{
    switch (strcmp(nv1.phongBan, nv2.phongBan))
    {
    case 1:
        return 1;
    case 0:
        if (strcmp(nv1.maNhanVien, nv2.maNhanVien) == 1)
            return 1;
    }
    return 0;
}

DANHSACH SortDanhSachNhanVien(const DANHSACH &ds)
{
    DANHSACH dsSorted = ds;
    sort(dsSorted.danhSach.begin(), dsSorted.danhSach.end(), NhanVienGreater);
    return dsSorted;
}
