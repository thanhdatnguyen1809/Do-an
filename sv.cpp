#include "sv.h"
sv::sv()
{
}
sv::sv(const string &mssv, const string &name, const string &classs, const string &faculty, const string &phonenumber)
{
    this->mssv = mssv;
    this->name = name;
    this->classs = classs;
    this->faculty = faculty;
    this->phonenumber;
}
sv::~sv()
{
}
void sv::show()
{
    cout << "***********************************************************************************************************" << endl;
    cout << "*                                         DANH SACH SINH VIEN                                             *" << endl;
    cout << "*                                                                                                         *" << endl;
    cout << "***********************************************************************************************************" << endl;
    cout << "MSSV: " << this->mssv << endl;
    cout << "Ho Va Ten: " << this->name << endl;
}
string sv::getmssv()
{
    return this->mssv;
}
void sv::setmssv(const string &mssv)
{
    this->mssv = mssv;
}
string sv::getname()
{
    return this->name;
}
void sv::setname(const string &name)
{
    this->name = name;
}
string sv::getclasss()
{
    return this->classs;
}
void sv::setclasss(const string &classs)
{
    this->classs = classs;
}
string sv::getfaculty()
{
    return this->faculty;
}
void sv::setfaculty(const string &faculty)
{
    this->faculty = faculty;
}
string sv::getphonenumber()
{
    return this->phonenumber;
}
void sv::setphonenumber(const string &phonenumber)
{
    this->phonenumber = phonenumber;
}