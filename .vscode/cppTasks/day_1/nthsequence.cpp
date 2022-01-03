#include <bits/stdc++.h>
using namespace std;

void serialSeq(int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << i << " ";
    }
}
void fibonacci(int n)
{
    int FbMn2 = 0;
    int FbMn1 = 1;
    cout<< FbMn2 << " " << FbMn1 << " ";
    int FbMn = FbMn1 + FbMn2;
    while (FbMn <= n)
    {
        cout << FbMn << " ";
        FbMn2 = FbMn1;
        FbMn1 = FbMn;
        FbMn = FbMn1 + FbMn2; //making fibonacci series
    }
}


int main()
{
    int a = 5;
    serialSeq(a);     //  serial decimal number sequence 
    cout << "\n";
    fibonacci(a);     //fibonacci sequence 

    return 0;
}

/*
Output  ->
PS F:\Cpp_programes> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ nthsequence.cpp -o nthsequence } ; if ($?) { .\nthsequence }
0 1 2 3 4 5 
0 1 1 2 3 5


}



*/