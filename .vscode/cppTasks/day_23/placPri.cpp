#include<iostream>
using namespace  std;
int main(){
    
    int t;cin>>t;
    while(t--){
        char A,B,C;
        cin>>A>>B>>C;
        char x,y;
        cin>>x>>y;
        // cout<<" X -"<<x<<" <---> "<<"Y -"<<y<<"\n";
        if(x==A && y==B||x==B && y==C||x==A && y==C){
            cout<<x<<"\n";
        }
        else {
            cout<<y<<"\n";
        }
        
        
    }
    return 0;
}
/*
2
A B C
A B
B C A
A C

*/