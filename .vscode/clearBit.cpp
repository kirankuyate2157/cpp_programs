#include<bits/stdc++.h>
using namespace std;
int clearBit(int n,int pos){
    int mask=~(1<<pos);
    return (n&mask);
}

int main() 
{
cout<<clearBit(7,2);
return 0;
}