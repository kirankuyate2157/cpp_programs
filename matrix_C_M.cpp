#include<bits/stdc++.h>
using namespace std;

int dp[1003][1003];

int go(int arr[],int start,int end){
    if(start >= end){
        return 0;
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }

    int min_cost=INT_MAX;
    for(int k=start;k < end;k++){
        int first_part=go(arr,start,k);
        int second_part=go(arr,k+1,end);
        min_cost=min(min_cost, first_part + second_part + arr[start]*arr[k+1]*arr[end+1]);
    }
    return dp[start][end]=min_cost;
}

int main(){
    int arr[]={40, 20, 30, 10, 30};
    int n=5;
    memset(dp,-1,sizeof(dp));
    cout<<go(arr,0,n-2);
    return 0;
}