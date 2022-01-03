#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>k;
        int ans=0;
        for(int i=1;i<=n-1;i++){
            if((n-1)%i==0){
                // ans++;
                k.push_back(i);
               
                }
            
        }
        for(int x:k){
            cout<<x<<",";
        }
        cout<<ans;
        cout<<"\n";
    }

    return 0;
}