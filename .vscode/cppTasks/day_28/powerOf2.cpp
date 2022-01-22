#include <bits/stdc++.h>
using namespace std;
bool isPowerofTwo(long long n)
{
    if(n==0)return false;
    while(!(n&1)){
        n>>1;
    }
    return (n==1)?true:false;
}
// {
//     if(n==0)return false;
//     return floor(log2(n))==ceil(log2(n))? true:false;
// }
    // {
    // n = n - (n & ~(n - 1));
    // cout<<n<<"-";
    // if (n == 0)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
    // }
    int main()
{
    long long x = 1099511627776;
    if (isPowerofTwo(x))
        cout << "yes";
    else
        cout << "no";
    return 0;
}