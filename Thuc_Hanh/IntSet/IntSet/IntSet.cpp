#include "IntSet.h"
#include <iomanip>
#include <iostream>
using namespace std;

IntSet::IntSet(const int inValues[], const int &inCount)
{
    int *newList = new int[inCount];
    int count = inCount;
    for (int i = 0; i < inCount; i++)
        newList[i] = inValues[i];
    this->DedupList(newList, count);
    if (this->values != NULL)
        delete[] this->values;
    this->values = new int[count];
    for (int i = 0; i < count; i++)
        this->values[i] = newList[i];
    this->count = count;
    delete[] newList;
}

IntSet::~IntSet()
{
    if (this->values == NULL)
        return;
    delete[] this->values;
}

istream &operator>>(istream &is, IntSet &intSet)
{
    cout << "Nhap so luong phan tu trong set: ";
    is >> intSet.count;
    int *list = new int[intSet.count]{0};
    for (int i = 0; i < intSet.count; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        is >> list[i];
    }
    IntSet::DedupList(list, intSet.count);
    if (intSet.values != NULL)
        delete[] intSet.values;
    intSet.values = new int[intSet.count];
    for (int i = 0; i < intSet.count; i++)
        intSet.values[i] = list[i];
    delete[] list;
    return is;
}

ostream &operator<<(ostream &os, const IntSet &intSet)
{
    os << "So luong phan tu: " << intSet.count << endl;
    os << "Gia tri cua set: ";
    for (int i = 0; i < intSet.count; i++)
        os << setw(5) << intSet.values[i];
    os << endl;
    return os;
}

IntSet IntSet::operator+(const IntSet &other) const
{
    int *newList = new int[this->count + other.count];
    int count = this->count;
    for (int i = 0; i < this->count; i++)
        newList[i] = this->values[i];
    for (int i = 0; i < other.count; i++)
    {
        for (int j = 0; j < count; j++)
            if (newList[j] == other.values[i])
                continue;
        this->AddElement(newList, count++, other.values[i]);
    }
    IntSet newIntSet = IntSet(newList, count);
    delete[] newList;
    return newIntSet;
}

IntSet IntSet::operator-(const IntSet &other) const
{
    int *newList = new int[this->count];
    int count = this->count;
    for (int i = 0; i < this->count; i++)
        newList[i] = this->values[i];
    for (int i = 0; i < other.count; i++)
        for (int j = 0; j < count; j++)
            if (newList[j] == other.values[i])
            {
                this->RemoveElement(newList, count, j);
                break;
            }
    IntSet newIntSet = IntSet(newList, count);
    delete[] newList;
    return newIntSet;
}

int IntSet::operator[](const int &pos) const
{
    if ((0 <= pos and pos < this->count))
        return this->values[pos];
    return -1; // return -1 if the position is not valid
}

bool IntSet::operator==(const IntSet &other) const
{
    if (this->count != other.count)
        return 0;
    for (int i = 0; i < this->count; i++)
        if (this->values[i] != other.values[i])
            return 0;
    return 1;
}

void IntSet::operator=(const IntSet &other)
{
    delete[] this->values;
    this->values = new int[other.count];
    for (int i = 0; i < other.count; i++)
        this->values[i] = other.values[i];
    this->count = other.count;
}

void IntSet::RemoveElement(int arr[], int &n, const int &pos)
{
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void IntSet::AddElement(int arr[], const int &pos, const int &value)
{
    arr[pos] = value;
}

void IntSet::DedupList(int arr[], int &n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j])
                IntSet::RemoveElement(arr, n, j);
}
