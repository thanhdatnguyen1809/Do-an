#include "QLS.h"

struct Node2
{
    BBook data;
    Node2 *next;
    Node2 *prev;
};

class QLSM : public QLS
{
public:
    Node2 *head;
    Node2 *tail;

public:
    QLSM();
    ~QLSM();
    bool isEmpty();
    void addHead(const BBook &);
    void addTail(const BBook &);
    void xuatds();
    void delTail();
    void delHead();
    void delAtK(const int &k);
    Node2 *searchID(const int &k);
    Node2 *searchName(const string &k);
    void searchAndPrintName(const string &k);
    void searchborrowerid(const int &);
    void searchborrower(const string &);
    void giahan(const int &, const int &);
    bool checkSM(const int &);
};
