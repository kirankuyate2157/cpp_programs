#include <bits/stdc++.h>
using namespace std;
void NonZsubAXor(int n)
{
    vector<int> arr(n + 1);
    unordered_map<int,int> mp(n+1);
    arr[0] = 1;
    int k = 1;
    for (int i = 2; i <= INT_MAX; i++)
    {
       int x = i ^ (i - 1);

       if (x == 0)
            {
                i++;
                continue;
            }
        arr[k++] = x;
        cout << k << "--";
        // mp[x]=1;
        if (k > n)
            break;
    }
    cout << "\n";
    for (int i = 0; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    // for(auto c:mp)cout<<c.first<<" : "<<c.second<<" ,";
    
}
void genNZArr(int n){
    vector<int>arr(n+1);
    arr[1]=1;int pw=2,index=2;
    while(index<=n){
        arr[index]=pw;
        int N=index;
        index++;
        for(int i=1;i<N&&index<n;i++){
           arr[index++]=arr[i];

        }
        pw*=2;
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // NonZsubAXor(n);
        genNZArr(n);
    }
    return 0;
}