#include<bits/stdc++.h>
using namespace std;
void fun(vector<int>&arr,int n){
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
}
int main(){
vector<int>v={1,2,3,4,5,6,7};
fun(v,v.size());
for(int x:v)cout<<x<<" ";

    return 0;
}