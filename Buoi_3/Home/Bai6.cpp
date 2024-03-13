#include <iostream>
using namespace std;
class So_phuc
{
private:
    double thuc;
    double ao;

public:
    So_phuc();
    void Nhap();
    void Xuat();
    double layphanthuc() const;
    double layphanao() const;
    void setThuc(double);
    void setAo(double);
    void congthuc(double, double);
    void congao(double, double);
    static void Thaydoigiatri(So_phuc &, So_phuc &);
    static void Conghaisophuc(So_phuc &, So_phuc &, So_phuc &);
};
int main()
{
    So_phuc sp1, sp2, sp3;
    sp1.Nhap();
    sp2.Nhap();
    sp1.Xuat();
    cout << endl;
    sp2.Xuat();
    cout << endl;
    So_phuc::Thaydoigiatri(sp1, sp2);
    sp1.Xuat();
    cout << endl;
    sp2.Xuat();
    cout << endl;
    So_phuc::Conghaisophuc(sp1, sp2, sp3);
    sp3.Xuat();
    cout << endl;
    return 0;
}
So_phuc::So_phuc()
{
    thuc = 0;
    ao = 0;
}
void So_phuc::Nhap()
{
    cout << "Nhap phan thuc: ";
    cin >> thuc;
    cout << "Nhap phan ao: ";
    cin >> ao;
}
void So_phuc::Xuat()
{
    cout << "(" << thuc << " + " << ao << "i) ";
}
// lay phan thuc phan ao
double So_phuc::layphanthuc() const
{
    return thuc;
}
double So_phuc::layphanao() const
{
    return ao;
}
// thay doi phan thuc phan ao
void So_phuc::setThuc(double real)
{
    thuc = real;
}

void So_phuc::setAo(double imag)
{
    ao = imag;
}

void So_phuc::Thaydoigiatri(So_phuc &sp1, So_phuc &sp2)
{
    double tempthuc = sp1.layphanthuc();
    double tempao = sp1.layphanao();
    sp1.setThuc(sp2.layphanthuc());
    sp1.setAo(sp2.layphanao());
    sp2.setThuc(tempthuc);
    sp2.setAo(tempao);
}

void So_phuc::congthuc(double real1, double real2)
{
    thuc = real1 + real2;
}

void So_phuc::congao(double imag1, double imag2)
{
    ao = imag1 + imag2;
}

void So_phuc::Conghaisophuc(So_phuc &sp1, So_phuc &sp2, So_phuc &sp3)
{
    sp3.congthuc(sp1.layphanthuc(), sp2.layphanthuc());
    sp3.congao(sp1.layphanao(), sp2.layphanao());
}