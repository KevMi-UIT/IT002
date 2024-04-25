#pragma once
#include "GiaSuc.h"
#include <string>

#define TIENG_KEU_DE "EEEEEE"
#define MAX_SUA_DE 5

class De : public GiaSuc
{
  private:
    string loai = "De";

  public:
    De() : GiaSuc(0, MAX_SUA_DE)
    {
    }
    ~De() = default;
    void keu() const;
};
