#include <iostream>
using namespace std;
void swap(int &a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bitswap(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main()
{
    int a = 60;
    int b = 23;
    cout << "initial value of a and b\n";

    cout << "a =" << a << "\n"
         << " b =" << b << "\n";


cout<<"after swaping \n";
swap(a,b);
    cout << "a =" << a << "\n"
         << " b =" << b<<"\n";

cout<<"after bit swaping\n ";
bitswap(a,b);
 cout << "a =" << a << "\n"
         << " b =" << b<<"\n";
    return 0;
}

/*


Output -->


PS F:\Cpp_programes\.vscode\cppTasks\day_1> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ swaping.cpp -o swaping } ; if ($?) { .\swaping }
initial value of a and b
a =60
 b =23
after swaping
a =23
 b =60
after bit swaping
 a =60
 b =23


 */