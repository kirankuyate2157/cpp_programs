#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = sizeof(arr) / sizeof(int);
    int q;
    cin >> q;
    for (int k = 0; k < q; k++)
    {
        int sum = 0;
        int a, b;
        cin>>a>>b;
        for (int i = a; i <= b; i++)
        {
            if (arr[i] > 0)
            {
                sum += arr[i];
            }
        }
        cout<<" sum is "<<sum<<"\n";
    }
    return 0;
}


/*
Output  -->


PS F:\Cpp_programes\.vscode\cppTasks\day_1> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ individualSum.cpp -o individualSum } ; if ($?) { .\individualSum }
3
1 3
 sum is 5
1 7
 sum is 27
9 10
 sum is 10


*/