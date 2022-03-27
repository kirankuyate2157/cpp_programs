#include <bits/stdc++.h>
using namespace std;

int minMove(int A, int B)
{
    if (A == B)
        return 0;
        int i = 1;
    for (; i < 100; i += 2)
    {
        if (A > B)
            swap(A, B);
        A += 1;
        A = A | i;
        if (A == B)
        {

         break;
        }
    }
    return i;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        cout<<minMove(A, B)<<"\n";
    }

    return 0;
}