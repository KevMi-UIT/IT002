#include "Bo.h"
#include "Cuu.h"
#include "De.h"
#include "GiaSuc.h"
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "Nhap so luong gia suc: ";
    cin >> n;

    cout << "Quy uoc: Bo - 1; Cuu - 2; De - 3" << endl;

    vector<GiaSuc *> ds;
    ds.resize(n);
    for (int i = 0; i < n; i++)
    {
        int sel;
        cout << "Nhap loai gia suc: ";
        cin >> sel;
        switch (sel)
        {
        case 1:
            ds[i] = (new Bo());
            break;
        case 2:
            ds[i] = (new Cuu());
            break;
        case 3:
            ds[i] = (new De());
            break;
        default:
            cout << "Gia suc khong hop le!" << endl;
            --i;
        }
    }

    // Cau a
    cout << "Tieng keu:" << endl;
    for (auto &it : ds)
        it->keu();

    // Cau b
    int soGiaSucGoc = ds.size();
    for (int i = 0; i < soGiaSucGoc; i++)
    {
        string currentType = ds[i]->getLoai();
        cout << currentType << endl;
        if (currentType == "Bo")
            for (int j = 0; j < ds[i]->getSoCon(); j++)
                ds.push_back(new Bo());
        else if (currentType == "Cuu")
            for (int j = 0; j < ds[i]->getSoCon(); j++)
                ds.push_back(new Cuu());
        else if (currentType == "De")
            for (int j = 0; j < ds[i]->getSoCon(); j++)
                ds.push_back(new De());
    }

    unordered_map<string, int> dsSauCung;
    int tongSoSua = 0;
    for (auto &it : ds)
    {
        dsSauCung[it->getLoai()]++;
        tongSoSua += it->getSoSua();
    }

    cout << "Tong so gia suc sau mot lua sinh:" << endl;
    for (auto &it : dsSauCung)
        cout << it.first << ": " << it.second << endl;
    cout << "Tong so sua: " << tongSoSua << "l" << endl;

    return 0;
}
