#include "Book.h"

class BBook : public Book
{
private:
    string bDate; // borrowed date
    string rDate; // returned date
    string borrower;
    int idBorrower;

public:
    BBook();
    BBook(const int &, const string &, const string &, const string &);
    ~BBook();
    string GetBDate();
    void SetBDate(const string &);
    string GetRDate();
    void SetRDate(const string &);
    string GetBorrower();
    void SetBorrower(const string &);
    int GetIdBorrower();
    void SetIdBorrower(const int &);
    void xuat();
};
