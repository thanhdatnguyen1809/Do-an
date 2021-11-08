#include "QLSM.h"

QLSM::QLSM()
{
    this->head = this->tail = NULL;
}

QLSM::~QLSM()
{
}

bool QLSM::isEmpty()
{ 
    return this->head == NULL;
}

Node2* createNode2(const BBook& x)
{ 
    Node2 *p = new Node2;
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->prev = NULL;
    p->data = x;
    return p;
}

void QLSM::addHead(const BBook &x)
{
    Node2 *p = createNode2(x);
    if (isEmpty())
        this->head = this->tail = p;
    else
    {
        p->next = this->head;
        this->head->prev = p; 
        this->head = p;       
    }
}

void QLSM::addTail(const BBook& x)
{
    Node2 *p = createNode2(x);
    if (isEmpty())
        addHead(x);
    else
    {
        this->tail->next = p; 
        p->prev = this->tail; 
        this->tail = p;       
    }
}



void QLSM::xuat()
{
    Node2 *p = this->head;
    while (p != NULL)
    {
        cout << "Thong tin sach:" << endl
        << "ID: " << p->data.GetID() << endl
        << "Ten sach: " << p->data.GetName() << endl
        << "Ngay muon: " << p->data.GetBDate() << endl
        << "Ngay tra: " << p->data.GetRDate() << endl
        << "Nguoi muon: " << p->data.GetBorrower() << endl
        << "_____________________________________" << endl;
        p = p->next;
    }
}