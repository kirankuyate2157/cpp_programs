#include<bits/stdc++.h>
using namespace std;
int getBit(int n,int pos){
    return (n | (1<<pos));
}
int main() 
{
// int n=0101;
cout<<getBit(7,3);
return 0;
}