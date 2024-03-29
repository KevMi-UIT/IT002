#pragma once
class Diem
{
  public:
    Diem();
    ~Diem();
    void Nhap();
    void Xuat() const;
    void setX(float);
    void setY(float);
    float getX() const;
    float getY() const;
    Diem TinhTien(float, float);
    Diem Quay(float);

  private:
    float x, y;
};
