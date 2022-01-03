#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void primeseq(int n)
{
    cout << n << "  -->  ";
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << i << " ";
        }
        if (isprime(i))
            cout << i << " ";
    }
    cout<<"\n";
}

int main()
{
    int n = 11;

    primeseq(n);
    primeseq(30);
    primeseq(100);
    return 0;
}


/*


Output  -->

PS F:\Cpp_programes\.vscode\cppTasks\day_1> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ primmsequ.cpp -o primmsequ } ; if ($?) { .\primmsequ }
prime numbers of ...
11  -->  1 2 3 5 7 11 
30  -->  1 2 3 5 7 11 13 17 19 23 29 
100  -->  1 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

*/