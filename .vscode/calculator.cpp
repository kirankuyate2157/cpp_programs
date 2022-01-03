#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"welcom to kiran calculator !!!\n";
     while(true){
    int a,b;
     
    cout<<"please enter 1 st number\n";
    cin>>a;
    char o;
    cout<<"enter oprator\n";
    cin>>o;

    cout<<"enter second number\n";
    cin>>b;
    int ans=0;
  
    if(o=='+'){
        ans=a+b;
    }
     else if(o=='-'){
        ans+=a-b;
    }
    else if(o=='*'){
        ans+=a*b;
    }else if(o=='/'){
        ans+=a/b;
    }else if(o=='%'){
        ans+=a%b;
    }
    else{
        cout<<" invalid input";
    }

    cout<<"ans  "<<ans<<"\n";
    }
}