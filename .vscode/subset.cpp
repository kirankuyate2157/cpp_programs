#include <bits/stdc++.h>
using namespace std;
void subSet(int arr[],int n){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        
    }
}
int main()
{
    int arr[] = {'a','b','c'};
    // int n = sizeof(arr) / sizeof(int);
    subSet(arr,3);
    return 0;
}
// output  -> 97 98 97 98 99 97 99 98 99 97 98 99  