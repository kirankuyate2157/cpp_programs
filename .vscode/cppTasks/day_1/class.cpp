#include<bits/stdc++.h>
using namespace std;

class assynment{


    private:   //default aceess specifier
    string  quetions="write class programe and explaind definetion declaration  acess member ";
    int marks=90;
    char grade = 'A';       //data members


    protected:
    int teacherSalary=70000;      //protected ...


    public:  //access specifier

    void showmarks(){
        cout<<marks<<"\n";
    }
    void showgrade(){   // defining the member functions
        cout<<grade<<"\n";
    }
    void showQuestion();      //declaration of member function 

};


 void assynment::showQuestion(){       //using scopRezolution defining the member function outside the class
     cout<<quetions<<" ";
 }


int main() 
{
    assynment a;
    a.showmarks();
    a.showQuestion();
return 0;
}



/*
output  --->


PS F:\Cpp_programes> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ class.cpp -o class } ; if ($?) { .\class }
90
write class programe and explaind definetion declaration  acess member 

*/