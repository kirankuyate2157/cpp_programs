#include <iostream>
using namespace std;
class academic
{
    string name = "kiran";
    string boardname = "HSC";
    float HscMarks = 87.56;
    float SSCMarks = 88.77;
    string email = "kirankuyate@gmail.com";

public:
    void acad()
    {
        cout << "------  academic  --------\n";
        cout << "name : " << name << "\n"
             << "email : " << email << "\n"
             << "boardname : " << boardname << "\n"
             << " HscMarks : " << HscMarks << "\n"
             << "SSCMarks : " << SSCMarks << "\n\n";
    }
};

class personal
{
    string name = "kiran kuyate";
    string email = "kiranpersonal@gmail.com";
    string address = "Dawachwadi";
    string status = "single";
    int age = 20;
    long long num = 9078569988;
    string DOB = "20-09-2002";

public:
    void per()
    {
        cout << " ------ personal ------\n";
        cout << "name : " << name << "\n"
             << "email : " << email << "\n"
             << "address : " << address << "\n"
             << "status : " << status << "\n"
             << "age : " << age << "\n"
             << "num : " << num << "\n"
             << "DOB : " << DOB << "\n\n";
    }
};
class peroffesional
{

    string name = "mr kiran kuyate";
    string inern = " gooogle";
    string traning = "ibm";
    string openSource = "GSOC";
    string course = "B.Tech computer";
    string university = "SPPU";
    string linekedin = "www.kirankuyate/linkedin.com";

public:
    void prof()
    {
        cout << " ------- profesional -------\n";
        cout << "name : " << name << "\n"
             << "course : " << course << "\n"
             << "inern :  " << inern << "\n"
             << "traning : " << traning << "\n"
             << "openSource : " << openSource << "\n"
             << "university : " << university << "\n"
             << "linekedin : " << linekedin << "\n\n";
    }
};

class biodata : public peroffesional, public personal, public academic
{
    string name = "kuyate kiran ";
    string edu = "UG";

public:
    void show()
    {
        cout << " ------ biodata ------\n";
        cout << name << "\n"
             << edu << "\n\n";
    }
};

int main()
{
    biodata ak;
    ak.show();
    ak.per();
    ak.acad();
    ak.prof();
    return 0;
}