#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class sv
{
private:
    string mssv;
    string name;
    string classs;
    string faculty;
    string phonenumber;

public:
    sv();
    sv(const string &, const string &, const string &, const string &, const string &);
    ~sv();
    void show();
    string getmssv();
    void setmssv(const string &);
    string getname();
    void setname(const string &);
    string getclasss();
    void setclasss(const string &);
    string getfaculty();
    void setfaculty(const string &);
    string getphonenumber();
    void setphonenumber(const string &);
};
