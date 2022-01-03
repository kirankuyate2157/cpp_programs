#include <bits/stdc++.h>
using namespace std;
int main()
{

    int arr[] = {5,4,2,9,4,10,8,6,3,12};
    int n = sizeof(arr) / sizeof(int);
    
    int pref[n];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
       
        for (int j = 0; j <= i; j++)
        {
            sum += arr[j];
        }
        pref[i]=sum;
        cout << pref[i]<< "  ";
    }

    int q;
    cin >> q;
for (int i = 0; i < q; i++)
{
int l,r,sum=0;
cin>>l>>r;
sum=pref[r]-(l==0?0:pref[r-1]);
cout<<sum<<"\n";
}




    return 0;
}