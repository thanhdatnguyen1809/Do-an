
#include "BBook.h"
struct Node
{
    Book data;
    Node *next; 
    Node *prev;
};

class QLS
{
public:
    Node *head;
    Node *tail;
public:
    QLS();
    ~QLS();
    bool isEmpty();
    void addHead(const Book &);
    void addTail(const Book &);
    void xuat();
    void delTail();
    void delHead();
    void delAtK(const int &k);
    Node *searchID(const int &k);
    Node *searchName(const string& k);

};  

