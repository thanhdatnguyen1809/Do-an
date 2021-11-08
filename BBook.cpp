#include "BBook.h"
#include <sstream>
BBook::BBook()
{
    this->ID = 0;
    this->name = "";
    this->bDate = "";
    this->rDate = "";
}

BBook::BBook(const int &id, const string &name, const string &bdate, const string &rdate)
{
    this->ID = id;
    this->name = name;
    this->bDate = bdate;
    this->rDate = rdate;
}

BBook::~BBook()
{
}



string BBook::GetBDate()
{
    return this->bDate;
}

void BBook::SetBDate(const string &s)
{
    this->bDate = s;
}

string BBook::GetRDate()
{
    string s = this->bDate;
    string t = s.substr(3, 2);
    stringstream geek(t);
    int a;
    geek >> a;

    // cout << t1 << kq << t2;

    return s.substr(0, 2) + '/' + to_string(a + 2) + '/' + s.substr(6, 4);
}

void BBook::SetRDate(const string &s)
{
    this->rDate = s;
}

string BBook::GetBorrower()
{
    return this->borrower;
}

void BBook::SetBorrower(const string &s)
{
    this->borrower = s;
}
