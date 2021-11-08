#include "Book.h"


Book::Book() : ID(0), name(""), author("") {}

Book::Book(const int &id, const string &name, const string &author)
    : ID(id), name(name), author(author) 
{}

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

