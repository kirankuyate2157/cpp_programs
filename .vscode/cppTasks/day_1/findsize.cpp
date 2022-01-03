#include <iostream>
using namespace std;

int main() {
//     sizeof()  <-- returb the size of parameters
\

    cout << "Size of char : " << sizeof(char) << " byte" << endl;
    cout << "Size of int : " << sizeof(int) << " bytes" << endl;
    cout << "Size of float : " << sizeof(float) << " bytes" << endl;
    cout << "Size of double : " << sizeof(double) << " bytes" << endl;

    return 0;
}

/*

Output  -->

PS F:\Cpp_programes\.vscode\cppTasks\day_1> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ findsize.cpp -o findsize } ; if ($?) { .\findsize }
Size of char : 1 byte
Size of int : 4 bytes
Size of float : 4 bytes
Size of double : 8 bytes

*/