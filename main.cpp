#include "qlsv.h"
#include <fstream>
#include "QLSM.h"
int quantity = 0; // số lượng của book

int main()
{
    ifstream filein; // file nhap sv
    ifstream fileAdd;
    ifstream fileDel;
    ifstream fileDel2; // mở file DelBook 1 lần nữa
    ifstream fileBorrow;
    ifstream delsv1; // mo file xoa sinh vien
    int chucnangmenu;

    bool isChoosed = false;
    qlsv db;
    QLS l1;  // nhap sach vao kho sach
    QLSM l2; // nhap sach vao he thong sach da muon
    sv p;
    string mssv, hoten, lop, khoa, sdt, t;
    int i = 1;
    string findName, findid, timsv, deleteid;
    Node *sn = new Node;
    Node *sid = new Node;
    cout << "Chuonng trinh quan ly thu vien...... " << endl;
    do
    {
        system("cls");
        cout << "1. Them sach" << endl;
        cout << "2. Xoa sach" << endl;
        cout << "3. Muon sach" << endl;
        cout << "4. Tra sach" << endl;
        cout << "5. Xuat sach" << endl;
        cout << "6. Tim kiem sach" << endl;
        cout << "7. Them sinh vien tu file" << endl;
        cout << "8. Xuat thong tin sinh vien" << endl;
        cout << "9. Tim kiem sinh vien" << endl;
        cout << "10. Xoa sinh vien" << endl;
        cout << "11. Gia han sach" << endl;
        cout << "Chon chuc nang: ";
        cin >> chucnangmenu;
        switch (chucnangmenu)
        {
        case 1:
            system("cls");
            fileAdd.open("AddBook.txt");
            // Thêm sách
            if (fileAdd.fail())
            {
                cout << "Failed to open this file!" << endl;
                isChoosed = true;
                //return -1;
            }
            while (!fileAdd.eof())
            {
                Book b1;
                int n, year;
                string s1, s2, s3;
                fileAdd >> n;

                b1.SetID(n);
                fileAdd.ignore();
                getline(fileAdd, s1);
                b1.SetName(s1);
                getline(fileAdd, s2);
                b1.SetAuthor(s2);
                fileAdd >> year;
                b1.SetPyear(year);
                fileAdd.ignore();
                getline(fileAdd, s3);
                b1.SetNation(s3);
                l1.addTail(b1);
                quantity++;
            }
            if(!isChoosed) cout << "Da them " << quantity << " cuon sach" << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            fileDel.open("DelBook.txt");
            int k; // ID sách cần xóa
            if (fileDel.fail())
            {
                cout << "Failed to open this file!" << endl;
                return -1;
            }
            while (!fileDel.eof())
            {
                fileDel >> k;
                if (k == 0)
                {
                    cout << "ERROR" << endl;
                    break;
                }
                Node *t = l1.searchID(k);
                cout << "Ban co chac xoa sach voi:" << endl;
                cout << "ID: " << t->data.GetID() << endl
                     << "Name: " << t->data.GetName() << endl
                     << "Author: " << t->data.GetAuthor() << endl
                     << "------------" << endl;
            }
            cout << "Sure? (Y/N)" << endl;
            char YN; // yes or no
            cin >> YN;
            fileDel2.open("DelBook.txt");
            switch (YN)
            {
            case 'Y':
            {
                while (!fileDel2.eof())
                {
                    int k;
                    fileDel2 >> k;
                    l1.delAtK(k);
                }

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
            system("pause");
            break;
        case 3:
            system("cls");
            fileBorrow.open("borrowbook.txt");
            if (fileBorrow.fail())
            {
                cout << "Failed to open this file!" << endl;
                return -1;
            }
            while (!fileBorrow.eof())
            {
                BBook b2;
                int n;
                string s1, s2, s3;
                fileBorrow >> n;

                b2.SetID(n);
                fileBorrow.ignore();
                getline(fileBorrow, s1);
                b2.SetName(s1);
                getline(fileBorrow, s2);
                b2.SetBDate(s2);
                getline(fileBorrow, s3);
                b2.SetBorrower(s3);
                l2.addTail(b2);
            }
            system("pause");
            break;
        case 4:
            break;
        case 5:
            system("cls");
            cout << "1. Xuat sach trong thu vien" << endl;
            cout << "2. Xuat sach da muon" << endl;
            int luachon;
            cin >> luachon;
            switch (luachon)
            {
            case 1:
                l1.xuat();
                break;
            case 2:
                l2.xuat();
                break;
            }
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "1. Tim kiem theo ID" << endl;
            cout << "2. Tim kiem theo ten" << endl;
            int s;
            cin >> s;
            switch (s)
            {
            case 1:
                cout << "Nhap ID sach can xuat" << endl;
                int findID; // ID sách cần tìm
                cin >> findID;
                if(findID <= quantity || findID >= 1)
                {
                    sid = l1.searchID(findID);
                    sid->data.xuat();
                }
                else cout << "Nhap loi" << endl;

                system("pause");
                break;
            case 2:
                cout << "Nhap ten sach can xuat" << endl; // ID sách cần tìm
                cin.ignore();
                getline(cin, findName);
                sn = l1.searchName(findName);
                sn->data.xuat();
                system("pause");
            default:
                cout << "Nhap loi" << endl;
                break;
            }
            break;
        case 7:
            system("cls");
            filein.open("SinhVien.txt", ios::in);
            if (filein.fail())
            {
                cout << "Failed to open this file!" << endl;
                return -1;
            }
            while (!filein.eof())
            {
                sv p;
                string mssv, hoten, lop, khoa, sdt, t;

                getline(filein, mssv);
                p.setmssv(mssv);
                getline(filein, hoten);
                p.setname(hoten);
                getline(filein, lop);
                p.setclasss(lop);
                getline(filein, khoa);
                p.setfaculty(khoa);
                getline(filein, sdt);
                p.setphonenumber(sdt);
                db.addtail(p);
            }
            filein.close();
            system("pause");
            break;
        case 8:
            system("cls");
            db.show();
            system("pause");
            break;
        case 9:
            system("cls");
            cout << "1. Tim kiem theo MSSV" << endl;
            cout << "2. Tim kiem theo ten sinh vien" << endl;
            int l;
            cin >> l;
            switch (l)
            {
            case 1:
                cout << "Nhap MSSV can tim" << endl;
                cin >> findid;
                db.searchid(findid);
                system("pause");
                break;
            case 2:
                cout << "Nhap ten sinh vien can tim" << endl;
                cin.ignore();
                getline(cin, timsv);
                db.searchname(timsv);
                system("pause");
                break;
            default:
                break;
            }
            break;
        case 10:
            system("cls");
            cout << "Nhap ma so sinh vien can xoa: ";
            cin >> deleteid;
            db.Delete(deleteid);
            system("pause");
            break;
        default:
            cout << "Da thoat khoi chuong trinh" << endl;
            return 0;
        }
    } while (true);
    return 0;
}
