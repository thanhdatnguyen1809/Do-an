#include "QLS.h"

QLS::QLS()
{
    this->head = this->tail = NULL;
}

QLS::~QLS()
{

}


Node* createNode(const Book& x)
{ 
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->prev = NULL;
    p->data = x;
    return p;
}

bool QLS::isEmpty()
{ 
    return this->head == NULL;
}

void QLS::addHead(const Book &x)
{
    Node *p = createNode(x);
    if (isEmpty())
        this->head = this->tail = p;
    else
    {
        p->next = this->head;
        this->head->prev = p; 
        this->head = p;       
    }
}

void QLS::addTail(const Book& x)
{
    Node *p = createNode(x);
    if (isEmpty())
        addHead(x);
    else
    {
        this->tail->next = p; 
        p->prev = this->tail; 
        this->tail = p;       
    }
}


void QLS::xuat()
{
    Node *p = this->head;
    while (p != NULL)
    {
        cout << "Thong tin sach:" << endl
        << "ID: " << p->data.GetID() << endl
        << "Ten sach: " << p->data.GetName() << endl
        << "Ten tac gia: " << p->data.GetAuthor() << endl
        << "_____________________________________" << endl;
        p = p->next;
    }
}



void QLS::delTail()
{
    if (!isEmpty())
    {
        Node *p = this->tail;
        this->tail = this->tail->prev; 
        this->tail->next = NULL;
        p->prev = NULL;
        delete p;
    }
}

void QLS::delHead()
{ 
    if (!isEmpty())
    {
        Node *p = this->head;
        this->head = this->head->next; 
        this->head->prev = NULL;
        delete p; 
    }
}


void QLS::delAtK(const int &k)
{
    Node *p = this->head;
    if (!isEmpty())
    {
        Node *q = new Node;
        while (p != NULL)
        { 
            // dem++;
            q = p;
            if (p->data.GetID() == k)
                break; 
            else
                p = p->next; 
        }
        if(p->next == NULL)
        {
            delTail();
            return;
        }
        if(p->prev == NULL)
        {
            delHead();
            return;
        }
        Node *r = this->head;
        while (r->next != q)
            r = r->next;   
        r->next = q->next; 
        (q->next)->prev = r;
        delete q;
    }
}


Node* QLS::searchID(const int &k)
{
    Node *p = this->head;
    while (p != NULL)
    {
        if (p->data.GetID() == k)
            return p;
        else
            p = p->next;
    }
    return NULL;
}

Node* QLS::searchName(const string& k)
{
    Node *p = this->head;
    while (p != NULL)
    {
        if (p->data.GetName() == k)
            return p;
        else
            p = p->next;
    }
    return NULL;
}