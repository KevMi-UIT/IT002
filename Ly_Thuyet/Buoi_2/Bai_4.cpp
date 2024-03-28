#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct HocSinh
{
    string maHocSinh;
    string hoTen;
    string gioiTinh;
    int Toan;
    int Ly;
    int Hoa;
    double diemtrungbinh;
};

struct DanhSach
{
    vector<HocSinh> danhsach;
    int soluong;
};

void inputHocSinh(HocSinh &);
void outputHocSinh(const HocSinh &);
DanhSach CreateDanhSachHocSinh();
void XuatDanhSachHocSinh(const DanhSach &);

int main()
{
    DanhSach ds = CreateDanhSachHocSinh();
    XuatDanhSachHocSinh(ds);
    return 0;
}

void inputHocSinh(HocSinh &hocsinh)
{
    cout << "Nhap ma hoc sinh: ";
    cin >> hocsinh.maHocSinh;
    cin.ignore();
    cout << "Nhap ho ten hoc sinh: ";
    getline(cin, hocsinh.hoTen);
    cout << "Nhap gioi tinh hoc sinh: ";
    cin >> hocsinh.gioiTinh;
    cout << "Nhap diem toan: ";
    cin >> hocsinh.Toan;
    cout << "Nhap diem hoa: ";
    cin >> hocsinh.Hoa;
    cout << "Nhap diem ly: ";
    cin >> hocsinh.Ly;
    hocsinh.diemtrungbinh = (hocsinh.Toan + hocsinh.Ly + hocsinh.Hoa) / 3;
}

void outputHocSinh(const HocSinh &hocsinh)
{
    cout << "Ho va ten:  " << hocsinh.hoTen << endl;
    cout << "Gioi tinh: " << hocsinh.gioiTinh << endl;
    cout << "Ma hoc sinh: " << hocsinh.maHocSinh << endl;
    cout << "Diem Trung Binh: " << hocsinh.diemtrungbinh << endl;
}

DanhSach CreateDanhSachHocSinh()
{
    DanhSach ds;
    cout << "Nhap so luong hoc sinh: ";
    cin >> ds.soluong;
    ds.danhsach.resize(ds.soluong);
    for (int i = 0; i < ds.soluong; i++)
    {
        cout << "Nhap thong tin cho nhan vien " << i + 1 << endl;
        inputHocSinh(ds.danhsach[i]);
    }
    return ds;
}

void XuatDanhSachHocSinh(const DanhSach &ds)
{
    for (int i = 0; i < ds.soluong; i++)
    {
        cout << "Hoc sinh thu " << i + 1 << ":" << endl;
        outputHocSinh(ds.danhsach[i]);
    }
}
