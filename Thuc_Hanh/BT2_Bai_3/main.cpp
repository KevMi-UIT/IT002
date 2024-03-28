#include "Candidate.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Candidate> Candidates;
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    Candidates.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin thi sinh thu " << i + 1 << endl;
        Candidates[i].Nhap();
    }
    cout << "Cac thi sinh co diem tong lon hon 15: " << endl;
    for (int i = 0; i < n; i++)
        if (Candidates[i].DiemHon15())
            Candidates[i].Xuat();
    return 0;
}
