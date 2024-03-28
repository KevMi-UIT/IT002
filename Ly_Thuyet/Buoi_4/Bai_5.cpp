#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cBook
{
  private:
    string maSach;
    string tenSach;
    int namXuatBan;
    int soTrang;

  public:
    void SetInfo(string ma, string ten, int nam, int trang);
    void Input();
    void Output() const;
    int GetNamXuatBan() const;
};

class cListBook
{
  private:
    vector<cBook> listBook;

  public:
    void InputList();
    void OutputList() const;
    void LatestBook() const;
};

int main()
{
    cListBook list;
    list.InputList();

    cout << "Danh sach cac sach: " << endl;
    list.OutputList();

    cout << "Thong tin sach xuat ban gan day nhat: " << endl;
    list.LatestBook();

    return 0;
}

void cBook::SetInfo(string ma, string ten, int nam, int trang)
{
    maSach = ma;
    tenSach = ten;
    namXuatBan = nam;
    soTrang = trang;
}

void cBook::Input()
{
    cout << "Nhap ma sach: ";
    cin >> maSach;
    cin.ignore();
    cout << "Nhap ten sach: ";
    getline(cin, tenSach);
    cout << "Nhap nam xuat ban: ";
    cin >> namXuatBan;
    cout << "Nhap so trang: ";
    cin >> soTrang;
}

void cBook::Output() const
{
    cout << "Ma sach: " << maSach << endl;
    cout << "Ten sach: " << tenSach << endl;
    cout << "Nam xuat ban: " << namXuatBan << endl;
    cout << "So trang: " << soTrang << endl;
}

int cBook::GetNamXuatBan() const
{
    return namXuatBan;
}

void cListBook::InputList()
{
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;
    listBook.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap thong tin cho sach thu " << i + 1 << ":\n";
        listBook[i].Input();
    }
}

void cListBook::OutputList() const
{
    for (int i = 0; i < listBook.size(); ++i)
    {
        cout << "Thong tin sach thu " << i + 1 << ":\n";
        listBook[i].Output();
        cout << endl;
    }
}

void cListBook::LatestBook() const
{
    if (listBook.empty())
    {
        cout << "Danh sach sach rong." << endl;
        return;
    }

    int latestYear = listBook[0].GetNamXuatBan();
    int latestIndex = 0;
    for (int i = 1; i < listBook.size(); ++i)
    {
        if (listBook[i].GetNamXuatBan() > latestYear)
        {
            latestYear = listBook[i].GetNamXuatBan();
            latestIndex = i;
        }
    }

    listBook[latestIndex].Output();
}
