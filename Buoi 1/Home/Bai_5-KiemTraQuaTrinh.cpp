#include <iostream>
#include <string>
using namespace std;
struct HocSinh
{
    string msv;
    string ten;
    double toan;
    double van;
    double ly;
    double hoa;
    double trungbinh;
    void diemtrungbinh()
    {
        trungbinh = (toan + van + ly + hoa) / 4;
    }
    void input()
    {
        cout << "Nhap ma so sinh vien: ";
        cin >> msv;
        cin.ignore();
        cout << " Nhap ho va ten: ";
        getline(cin, ten);
        cout << " Nhap diem toan: ";
        cin >> toan;
        cout << " Nhap diem van: ";
        cin >> van;
        cout << " Nhap diem ly: ";
        cin >> ly;
        cout << " Nhap diem hoa: ";
        cin >> hoa;
        diemtrungbinh();
    }
    void output()
    {
        cout << "Ma so sinh vien: " << msv << endl;
        cout << " Ho va ten" << ten << endl;
        cout << " Diem toan: " << toan << endl;
        cout << " Diem van: " << van << endl;
        cout << " Diem ly: " << ly << endl;
        cout << " Diem hoa: " << hoa << endl;
        cout << " Diem trung binh" << trungbinh << endl;
    }
};

int main()
{
    HocSinh x;
    x.input();
    x.output();
    return 0;
}