#include<bits/stdc++.h>
using namespace std;

void buildSQRT(vector<int>& box,int arr[],int n,int b){
    for(int i=0;i<n;i++){
        box[i/b]+=arr[i];
    }
}

void update(vector<int>& box,int arr[],int n,int b,int index,int x){
    box[index/b]=box[index/b]-arr[index]+x;
    arr[index]=x;
}

int query(vector<int>& box,int arr[],int n,int b,int l,int r){
    int sum=0;
    //1. [l,l+b-l%b)
    for(int i=l;i<=min(r,l+b-l%b-1);i++){
        sum+=arr[i];
    }

    if(l/b == r/b){
        return sum;
    }
    //2. [l+b-l%b,r-r%b)
    for(int i=(l+b-l%b)/b;i<(r-r%b)/b;i++){
        sum+=box[i];
    }
    //3.[r-r%b,r];
    for(int i=max(l,r-r%b);i<=r;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){

    int arr[]={4,6,2,6,19,3,7,24,5,4,46,4};
    int n=sizeof(arr)/sizeof(int);

    int b=sqrt(n);    
    vector<int> box(ceil(n/b),0);
    cout<<"Box Length = "<<b<<" :";
    buildSQRT(box,arr,n,b);

    for(int x:box){
        cout<<x<<" , ";
    }
    cout<<"\n";

    int q;
    cin>>q;


    while(q--){
        int type;
        cin>>type;
        // 1 l r

        if(type==1){
            int l,r;
            cin>>l>>r;
            int ans=query(box,arr,n,b,l,r);
            cout<<"max of range "<<l<< " to "<<r<<" is:"<<ans<<"\n";
        }else{
        // 2 index x
            int index,x;
            cin>>index>>x;
            update(box,arr,n,b,index,x);
        }
    }

    return 0;
}