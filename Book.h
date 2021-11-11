#include <iostream>
#include <string>
using namespace std;


class Book
{
protected:
    int ID;
    string name;
    string author;
    int pyear;
    string nation;
public:
    Book();
    Book(const int&, const string&, const string&);
    ~Book();
    int GetID();
    void SetID(const int&);
    string GetName();
    void SetName(const string&);
    string GetAuthor();
    void SetAuthor(const string&);
};

