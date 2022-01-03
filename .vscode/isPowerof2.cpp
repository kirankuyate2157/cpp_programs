#include<bits/stdc++.h>
using namespace std;
bool isPowerOf2(int n){
    return (n&& !(n&n-1));
}
int main() 
{
cout<<isPowerOf2(7);

return 0;
}