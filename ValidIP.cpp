#include<bits/stdc++.h>
using namespace std;
vector<string> output;
string s;
void go (int i,int counter,string cur){
    if(counter==5 && cur.length()==s.length()+3){
        output.push_back(cur);
        return ;
    }
    if(counter>4){
        return;
    }
    if(i>=s.length()){
        return;
    }
    go(i+1,counter+1,cur+s[i]+(counter==4?"":"."));
    if(s[i]=='0'){
        return;
    }
    go(i+2,counter+2,cur+s[i]+s[i+1]+(counter==4?"":"."));
    int num=stoi(s.substr(i,3));
    if(num<=255){
        go(i+3,counter+1,cur+s[i]+s[i+1]+s[i+2]+(counter==4?"":"."));

    }
}
int main() 
{

string s;
cin>>s;
go(0,1," ");
for(string o:output){
    cout<<o<<"\n";
}
cout<<"\n";
return 0;
}