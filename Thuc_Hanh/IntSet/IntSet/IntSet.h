#pragma once
#include <iostream>
using namespace std;
class IntSet
{
  private:
    int *values;
    int count;

  public:
    IntSet() : values(NULL), count(0)
    {
    }
    IntSet(const int[], const int &);
    ~IntSet();
    friend istream &operator>>(istream &, IntSet &);
    friend ostream &operator<<(ostream &, const IntSet &);
    IntSet operator+(const IntSet &) const;
    IntSet operator-(const IntSet &) const;
    int operator[](const int &) const;
    bool operator==(const IntSet &) const;
    void operator=(const IntSet &);
    static void RemoveElement(int[], int &, const int &);
    static void AddElement(int[], const int &, const int &);
    static void DedupList(int[], int &);
};
