#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

struct NhanVien
{
    char mnv[9];
    string hoten; // sai đề
    string phong; // sai đề
    int luong;
    int thuong;
    int lanh;
    void input()
    {
        cout << "Nhap ma nhan vien: ";
        cin >> mnv;
        cin.ignore();
        cout << "Nhap ho va ten: ";
        getline(cin, hoten);
        cout << "Nhap phong ban: ";
        getline(cin, phong);
        cout << "Nhap muc luong: ";
        cin >> luong;
        cout << "Nhap muc thuong: ";
        cin >> thuong;
    }
};

bool comparePhong(const NhanVien &nv1, const NhanVien &nv2)
{
    if (nv1.phong < nv2.phong)
    {
        {
            return nv1.phong < nv2.phong;
        }
    }
    else
    {
        if (nv1.phong == nv2.phong)
        {
            return nv1.mnv > nv2.mnv;
        }
    }
}
/*bool comparePhong(const NhanVien &nv1, const NhanVien &nv2)
{
    if (nv1.phong != nv2.phong)          // So sánh phòng ban
        return nv1.phong < nv2.phong;    // Sắp xếp theo phòng ban tăng dần
    return strcmp(nv1.mnv, nv2.mnv) < 0; // Nếu phòng ban giống nhau, so sánh mã nhân viên
}*/
int main()
{
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    vector<NhanVien> danhsachNV(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin cho nhan vien " << i + 1 << ": " << endl;
        danhsachNV[i].input();
    }

    // tong luong
    double tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong = tong + danhsachNV[i].luong + danhsachNV[i].thuong;
    }
    cout << "Tong luong cty phai tra: " << tong << endl;

    // nhân viên có lương thấp nhất;
    double tmp = danhsachNV[0].luong;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {

        if (tmp > danhsachNV[i].luong)
        {
            tmp = danhsachNV[i].luong;
            temp = i;
        }
    }
    cout << danhsachNV[temp].hoten << " voi muc luong thap nhat la: " << danhsachNV[temp].luong << endl;

    // số nhân viên có thưởng trên 12tr;

    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (danhsachNV[i].thuong > 12)
        {
            count = count + 1;
        }
    }
    cout << " So nhan vien co luong tren 12tr: " << count << endl;

    sort(danhsachNV.begin(), danhsachNV.end(), comparePhong);

    // In ra danh sách nhân viên đã được sắp xếp
    cout << "Danh sach nhan vien da sap xep theo phong ban:" << endl;
    for (const auto &nv : danhsachNV)
    {
        cout << nv.mnv << " " << nv.phong << endl;
    }
    return 0;
}