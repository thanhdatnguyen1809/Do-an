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

Node2 *createNode2(const BBook &x)
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

void QLSM::addTail(const BBook &x)
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

void QLSM::xuatds()
{
    Node2 *p = this->head;
    while (p != NULL)
    {
        cout << "Thong tin sach:" << endl
             << "ID: " << p->data.GetID() << endl
             << "Ten sach: " << p->data.GetName() << endl
             << "Ngay muon: " << p->data.GetBDate() << endl
             << "Ngay tra: " << p->data.GetRDate() << endl
             << "MSSV nguoi muon: " << p->data.GetIdBorrower() << endl
             << "Ten nguoi muon: " << p->data.GetBorrower() << endl
             << "_____________________________________" << endl;
        p = p->next;
    }
}

Node2 *QLSM::searchID(const int &k)
{
    Node2 *p = this->head;
    while (p != NULL)
    {
        if (p->data.GetID() == k)
            return p;
        else
            p = p->next;
    }
    return NULL;
}

void QLSM::searchAndPrintName(const string &k)
{
    bool is = false;
    Node2 *p = this->head;
    while (p != NULL)
    {
        if (p->data.GetName() == k)
        {
            p->data.xuat();
            is = true;
        }
        p = p->next;
    }
    if (!is)
        cout << "Khong co sach nay" << endl;
}

Node2 *QLSM::searchName(const string &k)
{
    Node2 *p = this->head;
    while (p != NULL)
    {
        if (p->data.GetName() == k)
            return p;
        else
            p = p->next;
    }
    return NULL;
}
void QLSM::searchborrowerid(const int &i)
{
    int k = 0;
    Node2 *p = this->head;
    while (p != nullptr)
    {
        if (p->data.GetIdBorrower() == i)
        {
            k++;
            cout << "Thong tin sach:" << endl
                 << "ID: " << p->data.GetID() << endl
                 << "Ten sach: " << p->data.GetName() << endl
                 << "Ngay muon: " << p->data.GetBDate() << endl
                 << "Ngay tra: " << p->data.GetRDate() << endl
                 << "_____________________________________" << endl;
        }
        p = p->next;
    }
    cout << "Tong so sach dang muon: " << k << endl
         << "_____________________________________" << endl;
}
void QLSM::searchborrower(const string &b)
{
    int k = 0;
    Node2 *p = this->head;
    while (p != nullptr)
    {
        if (p->data.GetBorrower() == b)
        {
            k++;
            cout << "Thong tin sach:" << endl
                 << "ID: " << p->data.GetID() << endl
                 << "Ten sach: " << p->data.GetName() << endl
                 << "Ngay muon: " << p->data.GetBDate() << endl
                 << "Ngay tra: " << p->data.GetRDate() << endl
                 << "_____________________________________" << endl;
        }
        p = p->next;
    }
    cout << "Tong so sach dang muon: " << k << endl
         << "_____________________________________" << endl;
}
void QLSM::giahan(const int &a, const int &b)
{
    string s;
    Node2 *p = this->head;
    while (p != nullptr)
    {
        if (p->data.GetIdBorrower() == a && p->data.GetID() == b)
        {
            p->data.xuat();

            cout << "Ban co muon gia han sach them 2 thang ko" << endl;
            cout << "Sure? (Y/N)" << endl;
            char YN; // yes or no
            cin >> YN;
            switch (YN)
            {
            case 'Y':
            {
                p->data.SetBDate(p->data.GetRDate());
                cout << "Ban da gia han sach thanh cong sach them 2 thang nua" << endl;
                cout << "Ngay ban phai tra la: " << p->data.GetRDate() << endl;
                break;
            }
            case 'N':
                break;
            default:
            {
                cout << "ERROR" << endl;
                break;
            }
            }
            break;
        }
        p = p->next;
    }
}