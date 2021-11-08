#include "sv.h"
struct nodesv
{
    sv data;
    nodesv *next;
    nodesv *prev;
};
class qlsv
{
private:
    nodesv *head;
    nodesv *tail;

public:
    qlsv();
    ~qlsv();
    void add(const sv &);
    void show();
    void searchname(const string &);
    void searchid(const string &);
};
