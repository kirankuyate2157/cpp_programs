#include <bits/stdc++.h>
using namespace std;
int setBit(int x, int n)
{

    return x | (1 << n);
}

int unSetBit(int x, int n)
{
    return x & (~(1 << n));
}
void isSet(int x, int n)
{
    if ((x >> n & 1) == 1)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
}

int countSetBit(int x)
{
    int count = 0;
    while (x)
    {

        x = x - (x & (~x + 1));
        count++;
    }
    return count;
}
// 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 1 0 1 0 0 0 1 0 1 0 1 1 0 0 1 1 1 1 0 0 0 1 0 0 1 1 0 1 0 1 0 1 1 1 1 0 0

int countTotalSetbit(int n)
{
    int cnt = 0, i = 2,j=0;
    while (n /i > 0|| j==1)
    {
        // cout<<i<<" ,";
        int a = (n / i) ;
        if(n/(i*2)<=0)j++;
        cnt+=a*(i/2);
        int rem= ((n % i) + 1) - i / 2;
        if(rem>0)cnt+=rem;
        i *= 2;
    }
    // cout << cnt << " \n";
    return cnt;

}
int main()
{
    int x = 14;
    cout << countTotalSetbit(x);
    // cout << countSetBit(x);
    return 0;
}