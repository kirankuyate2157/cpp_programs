#include<bits/stdc++.h>
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    
    string ans="";
    unordered_map<int,string> m;
    m[1]="2";
    m[2]="3";
    m[3]="22";
    m[4]="23";
    m[5]="32";
    m[6]="33";

    while(n > 0){
        //cout<<n<<"\n";
        if(m.find(n) != m.end()){
            ans.append(m[n]);
            break;
        }
        int x=log2(n);
        x=1<<x;
        int start=x-1;
        int end=start+x-1;

        // cout<<n<<" "<<start<<" "<<end<<" "<<(start+end)/2<<"\n";

        if(n <= (start+end)/2){
            ans.push_back('2');
            n=n-x/2;
        }else{
            ans.push_back('3');
            n=n-x;
        }
    }
    //reverse(ans.begin(),ans.end());
    cout<<ans;

    //vector<int> prime=primesieve();

    // while(t--){
    //         int n,m;    
    //         cin>>n>>m;
        	
    //     	int arr[n];
    //     	int b[n];
        	
    // }

    return 0;
}