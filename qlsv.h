#include "sv.h"
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
    void searchname(const string &);
    void searchid(const string &);
};