#pragma once
#include <string>

using namespace std;

#define MAX_SO_CON 20

class GiaSuc
{
  protected:
    int soCon;
    int soSua;
    string loai;

  public:
    GiaSuc(const int &inSoCon = 0, const int &inSoSua = 0, const string & = "");
    virtual ~GiaSuc() = default;
    void Xuat() const;
    virtual void keu() const = 0;
    int getSoCon() const;
    int getSoSua() const;
    string getLoai() const;
    static int randomCon();
    static int randomSua(const int &);
};
