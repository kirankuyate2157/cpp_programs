#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    int arr[100001]={0};
    while (t--)
    {
        int n;
        cin >> n;
        arr[n]++;
    }
    for (int i = 0; i < 100001; i++)
    {
        while (arr[i]--)
        {
            cout << i << "\n";
        }
    }

    return 0;
}

