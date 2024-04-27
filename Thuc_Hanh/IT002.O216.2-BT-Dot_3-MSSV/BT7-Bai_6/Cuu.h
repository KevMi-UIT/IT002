#pragma once
#include "GiaSuc.h"
#include <string>

#define TIENG_KEU_CUU "Beeeee"
#define MAX_SUA_CUU 5

class Cuu : public GiaSuc
{
  private:
    string loai;

  public:
    Cuu() : GiaSuc(0, MAX_SUA_CUU, "Cuu")
    {
    }
    ~Cuu() = default;
    void keu() const override;
};
