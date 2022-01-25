// you have given two arrays which contains elements n,m
// your work is that ki merge two array  and give us sorted array.
// array1=[4,6,2,9,13,23]
// array2=[8,1,4,12,17,21,19]

// ans.
// [1, 2, 4, 4, 6, 8, 9, 12, 13, 17, 19, 21, 23]
#include <bits/stdc++.h>
using namespace std;

int f(int x){
    if(x>100)return x/10;
    else return f(f(x-11));
}
int main()
{
   
    // int size=5,arr[size]={1,2};
    // int n=sizeof(arr)/sizeof(int);

    // cout<<n<<"----";

    int x=9;
    cout<<f(x);

    return 0;
}