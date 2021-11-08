#include "qlsv.h"
#include <cstring>
qlsv::qlsv()
{
    this->head = nullptr;
    this->tail = nullptr;
}
qlsv::~qlsv()
{
}
nodesv *create(const sv &s)
{
    nodesv *p = new nodesv;
    p->data = s;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
void qlsv::add(const sv &s)
{
    nodesv *p;
    p = create(s);
    if (this->head == nullptr)
    {
        this->head = p;
        this->tail = p;
    }
    else
    {
        this->tail->next = p;
        p->prev = this->tail;
        this->tail = p;
    }
}
void qlsv::show()
{
    nodesv *p = this->head;
    while (p != nullptr)
    {
        p->data.show();
        p = p->next;
    }
}
void qlsv::searchid(const string &t)
{
    nodesv *p = this->head;
    while (p != nullptr)
    {
        if (p->data.getmssv() == t)
        {
            p->data.show();
        }
        p = p->next;
    }
    if (p == nullptr)
    {
        cout << "Khong tim thay sinh vien can tim" << endl;
    }
}
void qlsv::searchname(const string &t)
{
    nodesv *p = this->head;
    while (p != nullptr)
    {
        if (p->data.getname() == t)
        {
            p->data.show();
        }
        p = p->next;
    }
    if (p == nullptr)
    {
        cout << "Khong tim thay sinh vien can tim" << endl;
    }
}
