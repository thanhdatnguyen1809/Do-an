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
    string findName, timsv;
    int findid;
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
                // return -1;
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
            if (!isChoosed)
                cout << "Da them " << quantity << " cuon sach" << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            fileDel.open("DelBook.txt");
            int k; // ID sách cần xóa
            if (fileDel.fail())
            {
                cout << "Failed to open this file!" << endl;
                // return -1;
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
                // return -1;
            }
            while (!fileBorrow.eof())
            {
                BBook b2;
                int idbook;
                int idsv;
                int k;
                string s1, s2, s3;
                fileBorrow >> idbook;
                fileBorrow.ignore();
                getline(fileBorrow, s1);
                getline(fileBorrow, s2);
                fileBorrow >> idsv;
                fileBorrow.ignore();
                getline(fileBorrow, s3);
                if (l1.checkNameAndID(idbook, s1) && db.checkNameAndMssv(idsv, s3) && !l2.checkSM(idbook))
                {
                    if (db.tongsosach(idsv) > 3)
                    {
                        cout << "_______________________________________" << endl
                             << "MSSV: " << idsv << endl
                             << "Ho va ten: " << s3 << endl
                             << "muon khong thanh cong sach co : " << endl
                             << "Id: " << idbook << endl
                             << "Ten sach: " << s1 << endl
                             << "boi vi muon qua 3 quyen sach" << endl
                             << "_______________________________________" << endl;
                        b2.SetID(idbook);
                        b2.SetName(s1);
                        b2.SetBDate(s2);
                        b2.SetIdBorrower(idsv);
                        b2.SetBorrower(s3);
                    }
                    else
                    {
                        b2.SetID(idbook);
                        b2.SetName(s1);
                        b2.SetBDate(s2);
                        b2.SetIdBorrower(idsv);
                        b2.SetBorrower(s3);
                        l2.addTail(b2);
                    }
                }
                else
                {
                    // fileBorrow.ignore();
                    // getline(fileBorrow, s1);
                    // getline(fileBorrow, s2);
                    // getline(fileBorrow, s3);
                    cout << "Du lieu sach co ID: " << idbook << " khong hop le" << endl;
                }
            }
            system("pause");
            break;
        case 4:
            system("cls");
            cout<<"Nhap ma id sach can tra: ";
            int kk;
            cin>>kk;
            l2.Delete(kk);
            system("pause");
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
                l1.xuatds();
                break;
            case 2:
                l2.xuatds();
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
                system("cls");
                cout << "Nhap ID sach can xuat" << endl;
                int findID; // ID sách cần tìm
                cin >> findID;
                Node2 *sidsm;
                sidsm = new Node2;
                if (findID <= quantity && findID >= 1)
                {
                    sidsm = l2.searchID(findID);
                    if (sidsm == NULL)
                    {
                        sid = l1.searchID(findID);
                        if (sid == NULL)
                        {
                            cout << "Khong co sach nay" << endl;
                            break;
                        }
                        else
                            sid->data.xuat();
                    }
                    else
                        sidsm->data.xuat();
                }
                else
                {
                    cout << "Khong co sach nay trong thu vien" << endl;
                }

                break;
            case 2:
                cout << "Nhap ten sach can xuat" << endl; // ID sách cần tìm
                cin.ignore();
                getline(cin, findName);
                if (l2.searchName(findName) != NULL)
                {
                    l2.searchAndPrintName(findName);
                }
                else
                {
                    l1.searchAndPrintName(findName);
                }

                // system("pause");
                break;
            default:
                cout << "Nhap loi" << endl;
                break;
            }
            system("pause");
            break;
        case 7:
            system("cls");
            filein.open("SinhVien.txt", ios::in);
            if (filein.fail())
            {
                cout << "Failed to open this file!" << endl;
                return -1;
            }

            else
            {
                while (!filein.eof())
                {
                    sv p;
                    string hoten, lop, khoa, sdt, t;
                    int mssv;
                    filein >> mssv;
                    filein.ignore();
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
                cout << "Them thanh cong file sinh vien" << endl;
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
            int f;
            cin >> f;
            switch (f)
            {
            case 1:
                cout << "Nhap MSSV can tim" << endl;
                cin >> findid;

                db.searchid(findid);
                l2.searchborrowerid(findid);
                system("pause");
                break;
            case 2:
                cout << "Nhap ten sinh vien can tim" << endl;
                cin.ignore();
                getline(cin, timsv);
                db.searchname(timsv);
                l2.searchborrower(timsv);
                system("pause");
                break;
            default:
                break;
            }
            break;
        case 10:
            int deleteid;
            system("cls");
            cout << "Nhap ma so sinh vien can xoa: ";
            cin >> deleteid;
            db.Delete(deleteid);
            system("pause");
            break;
        case 11:
            system("cls");
            int a, b;
            cout << "Nhap ma so sinh vien : ";
            cin >> a;
            cout << "Nhap vao ma sach can gia han: ";
            cin >> b;
            l2.giahan(a, b);
            system("pause");
            break;
        default:
            cout << "Da thoat khoi chuong trinh" << endl;
            return 0;
        }
    } while (true);
    return 0;
}
