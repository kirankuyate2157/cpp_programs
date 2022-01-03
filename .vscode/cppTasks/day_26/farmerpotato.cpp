#include <bits/stdc++.h>
using namespace std;
// input --> 2 test case
// 1 3
// 4 3
void primenum(int n){
    vector<int >ans;
    ans.push_back(1);
    while(n>1){
        int flag=0;
        for(int i=2;i<n;i++){
            if(n%i==0){
                flag=1;
                break;
            }
        }
        if(!flag){
            ans.push_back(n);
        }
    }
    for(int ele:ans){
            cout<<ele<<" ";
        }
}
int main() {

   

    int t;cin>>t;
    while(t--){
        int st1,nd2;
        cin>>st1>>nd2;
 cout<<"hii";
    	primenum(st1+nd2);
    	// for(int ele:v){
	    //     cout<<ele<<" ";
	    // }
    }
	return 0;
}
