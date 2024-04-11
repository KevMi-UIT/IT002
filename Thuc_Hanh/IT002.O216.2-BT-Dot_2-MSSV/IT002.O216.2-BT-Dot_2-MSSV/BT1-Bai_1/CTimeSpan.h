#pragma once
class CTimeSpan
{
  private:
    double length;

  public:
    CTimeSpan(const double &inLength = 0) : length(inLength)
    {
    }
    void Nhap();
    void Xuat() const;
    double getLength() const;
    CTimeSpan Cong(const CTimeSpan &) const;
    CTimeSpan Tru(const CTimeSpan &) const;
    CTimeSpan Nhan(const CTimeSpan &) const;
    CTimeSpan Chia(const CTimeSpan &) const;
    bool Bang(const CTimeSpan &) const;
    bool Khac(const CTimeSpan &) const;
    bool LonHon(const CTimeSpan &) const;
    bool LonHonBang(const CTimeSpan &) const;
    bool BeHon(const CTimeSpan &) const;
    bool BeHonBang(const CTimeSpan &) const;
};
