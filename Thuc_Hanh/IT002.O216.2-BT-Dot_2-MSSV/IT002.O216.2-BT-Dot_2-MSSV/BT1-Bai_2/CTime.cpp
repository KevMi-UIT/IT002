#include "CTime.h"

int CTime::TinhSoGiay() const
{
    return (this->gio * 3600 + this->phut * 60 + this->giay);
}
