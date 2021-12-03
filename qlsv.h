#include "sv.h"
static int j=0;
struct nodesv
{
    sv data;
    nodesv *next;
    nodesv *prev;
};
class qlsv
{
public:
    nodesv *head;
    nodesv *tail;

public:
    qlsv();
    ~qlsv();
    bool isEmpty();
    void addhead(const sv &);
    void addtail(const sv &);
    void show();
    void Delete(const int &);
    void searchname(const string &);
    void searchid(const int &);
    nodesv* searchName(const string&);
    nodesv* searchID(const int &);
    bool checkMssv(const int&);
    bool checkNamesv(const string&);
    bool checkNameAndMssv(const int& , const string&);
    int tongsosach(const int&);
};