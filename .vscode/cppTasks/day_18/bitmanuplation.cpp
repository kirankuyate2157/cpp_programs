#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int addition(int a, int b)
{
    return a+(b);
}
int substr(int a, int b)
{
    int mask = ~b+ 1;
    return a + mask;
}
int  muldouble(int a){
    return a<<2;
}

void swap(int& a,int& b){     //swaping two values

    a=a^b;
    b=a^b;
    a=a^b;
    // cout<<"a= "<<a<<"\t\t"<<"b ="<<b;
}

string additionss( string a,string b){
    string  result;
    int i=a.length()-1,j=b.length()-1;
    int carry=0;
    
    while(i>=0 || j>=0){
        int sum=carry;
        if(i>=0){sum+=a[i--]-'0';}
        if(j>=0){sum+=a[j--]-'0';}
        // carry=sum/2;
        carry=sum>1?1:0;
        result+=to_string(sum%2);
    }
    result+=to_string(carry);
    // reverse(result.begin(),result.end() );
    cout<<"run succesfully\n";
    return result;

}


int main()
{
    int a = 5, b = 20;
    string c="1101",d="100";
    // swap(a,b);
    // cout << addition(a, b) << "\n";
    // cout << substr(b,a)<<"\n";
    // cout<<muldouble(a)<<"\n";
    cout<<additionss(c,d);
    return 0;
}