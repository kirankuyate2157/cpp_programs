#include<bits/stdc++.h>
using namespace std;

int build(vector<int>& tree,int l,int h,int index,int arr[]){
    if(l > h){
        return 0;
    }
    if(l==h){
        return tree[index]=arr[l];
    }
    int mid=(l+h)/2;
    return tree[index]=build(tree,l,mid,2*index+1,arr)+build(tree,mid+1,h,2*index+2,arr);
}

int query(vector<int>& tree,vector<int>& lazy,int lt,int ht,int l,int h,int index){
    if(l > ht || h < lt || lt > ht)return 0;

    if(lazy[index] != 0){
        tree[index]+=lazy[index]*(ht-lt+1);
        lazy[2*index+1]+=lazy[index];
        lazy[2*index+2]+=lazy[index];
        lazy[index]=0;
    }

    if(l<=lt && h >= ht)return tree[index];
    int mid=(lt+ht)/2;
    return query(tree,lazy,lt,mid,l,h,2*index+1)+query(tree,lazy,mid+1,ht,l,h,2*index+2);
}

void update(vector<int>& tree,vector<int>& lazy,int lt,int ht,int l,int h,int x,int index){
    if(l > ht || h < lt || lt > ht)return;

    if(lazy[index] != 0){
        tree[index]+=lazy[index]*(ht-lt+1);
        lazy[2*index+1]+=lazy[index];
        lazy[2*index+2]+=lazy[index];
        lazy[index]=0;
    }

    if(l<=lt && h >= ht){
        tree[index]+=x*(ht-lt+1);
        lazy[2*index+1]+=x;
        lazy[2*index+2]+=x;
    }else{
        int mid=(lt+ht)/2;
        update(tree,lazy,lt,mid,l,h,x,2*index+1);
        update(tree,lazy,mid+1,ht,l,h,x,2*index+2);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
}

int main(){
    int arr[]={6, 2, 5, 1, 8, 9, 12, 6, 15, 27, 19, 31, 94, 11, 43, 2, 9, 66, 3};
    int n=10;

    vector<int> tree(4*n,0),lazy(4*n,0);

    build(tree,0,n-1,0,arr);

    // for(int i=0;i<4*n;i++){
    //     cout<<i<<":"<<tree[i]<<" , ";
    // }
    // cout<<"\n";

    int q;
    cin>>q;

    while(q--){
        int type;
        cin>>type;
        // 1 l r
        if(type==1){
            int l,r;
            cin>>l>>r;
            int ans=query(tree,lazy,0,n-1,l,r,0);
            cout<<"sum of range "<<l<< " to "<<r<<" is:"<<ans<<"\n";
        }else{
        // 2 index x
            int l,r,x;
            cin>>l>>r>>x;
            update(tree,lazy,0,n-1,l,r,x,0);
        }
    }
    return 0;
}