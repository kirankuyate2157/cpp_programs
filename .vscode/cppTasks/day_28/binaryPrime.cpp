#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int tc=1;
    for (int i = 0; i<s.length(); i++)
    {
       if(s[i]=='1'&&(s[i+1]=='1'||s[i+1]=='0')){
           cout<<"yes\n";
           tc=0;
           break;
       }

    }
   if(tc){
       cout<<"no\n";
   }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}