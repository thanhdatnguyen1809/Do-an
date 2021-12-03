#include "QLS.h"
#include <fstream>
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


void QLS::xuatds()
{
    static int dem = 0;
    cout << "Thong tin sach trong thu vien:" << endl
    << "_____________________________________";
    Node *p = this->head;
    ofstream ofs("filexuatsachtrongthuvien.txt");
    while (p != NULL)
    {
        cout << "ID: " << p->data.GetID() << endl
        << "Ten sach: " << p->data.GetName() << endl;
        cout << "_____________________________________" << endl;
        ofs << "ID: " << p->data.GetID() << endl
        << "Ten sach: " << p->data.GetName() << endl;
        ofs << "_____________________________________" << endl;
        dem++;
        p = p->next;
    }
    ofs.close();
    cout << "Trong thu vien dang co " << dem << " cuon sach" << endl;
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

Node* QLS::searchName(const string &k)
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

void QLS::searchAndPrintName(const string& k)
{
    bool is = false;
    Node *p = this->head;
    while (p != NULL)
    {
        if (p->data.GetName() == k)
        {
            p->data.xuat();
            is = true;
        }
        p = p->next;
        
    }
    if(!is) cout << "Khong co sach nay" << endl;
    
}

bool QLS::checkID(const int&id)
{
    if(this->searchID(id) != NULL)
        return true;
    return false;
}

bool QLS::checkName(const string& name)
{
    if(this->searchName(name) != NULL)
        return true;
    return false;
}

bool QLS::checkNameAndID(const int& id, const string& name)
{
    Node *check = this->searchID(id);
    if(check != NULL)
    {
        if(check->data.GetName() == name)
            return true;
    }
    return false;
}
