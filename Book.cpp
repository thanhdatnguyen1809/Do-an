#include "Book.h"

Book::Book() : ID(0), name(""), author("") {}

Book::Book(const int &id, const string &name, const string &author)
    : ID(id), name(name), author(author)
{
}

Book::~Book()
{
}

int Book::GetID()
{
    return this->ID;
}

void Book::SetID(const int &id)
{
    this->ID = id;
}

string Book::GetName()
{
    return this->name;
}

void Book::SetName(const string &name)
{
    this->name = name;
}

string Book::GetAuthor()
{
    return this->author;
}

void Book::SetAuthor(const string &author)
{
    this->author = author;
}

int Book::GetPyear()
{
    return this->pyear;
}

void Book::SetPyear(const int &year)
{
    this->pyear = year;
}

string Book::GetNation()
{
    return this->nation;
}
void Book::SetNation(const string &n)
{
    this->nation = n;
}

void Book::xuat()
{
    cout << "Thong tin cua sach: " << endl;
    cout << "ID: " << this->GetID() << endl;
    cout << "Name: " << this->GetName() << endl;
    cout << "Author: " << this->GetAuthor() << endl;
    cout << "Nam xuat ban: " << this->GetPyear() << endl;
    cout << "Xuat xu: " << this->GetNation() << endl;
}