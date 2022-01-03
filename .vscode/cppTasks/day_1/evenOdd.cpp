#include <bits/stdc++.h>
using namespace std;

void check(int a){
       if (a % 2 == 0)
    {
        cout << "number is even \n";
    }
    else
    {
        cout << "Number is Odd \n";
    }
}


int main()
{

    int a = 45,b=24,c=17,d=100;

    check(a);
    check(b);
    check(c);
    check(d);



    

    return 0;
}

/*

Output -->

PS F:\Cpp_programes> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ evenOdd.cpp -o evenOdd } ; if ($?) { .\evenOdd }
Number is Odd 
number is even 
Number is Odd 
number is even 


*/