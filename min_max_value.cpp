#include<bits/stdc++.h>
using namespace std;

int dp[1003][1003];

int go(string& s,int start,int end){
    if(start > end){
        return INT_MAX;
    }
    if(start==end){
        return s[start]-'0';
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }   
    int ans=INT_MIN;

    for(int k=start;k<=end;k++){
        if(s[k]=='*'){
            int left=go(s,start,k-1);
            int right=go(s,k+1,end);
            if(left==INT_MAX){
                left=1;
            }else if(right==INT_MAX){
                right=1;
            }
            ans=max(ans,left*right);
        }else if(s[k]=='+'){
            int left=go(s,start,k-1);
            int right=go(s,k+1,end);
            if(left==INT_MAX){
                left=0;
            }else if(right==INT_MAX){
                right=0;
            }
            ans=max(ans,left+right);
        }
    }
    return dp[start][end]=(ans==INT_MIN?INT_MAX:ans);
}

int main(){
    string s="1+2*3+4*5";
    memset(dp,-1,sizeof(dp));
    cout<<go(s,0,s.length()-1)<<"\n";
    return 0;
}