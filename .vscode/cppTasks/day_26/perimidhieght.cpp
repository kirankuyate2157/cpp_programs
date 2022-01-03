#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,ans=0, i = 1;
        cin >> n;
        // cout<<"i -";
        while (ans<=n)
        {
            ans=(i * (i + 1)) / 2 ;
            // cout<<i<<",";
            i++;
        }
        cout<<i-2<<"\n";
    }

    return 0;
}