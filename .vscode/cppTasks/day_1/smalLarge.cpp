#include<bits/stdc++.h>
using namespace std;
int main() 
{

int arr[]={3,7,1,2,9,3,5,3,6};
int n=sizeof(arr)/sizeof(int);
int large=INT_MIN;
int  small=INT_MAX;
for(int i=0;i<n;i++){
    if(arr[i]<small){
        small=arr[i];
    }
    if(arr[i]>large){
        large=arr[i];
    }
}

cout<<"large numbere is  "<<large<<" \n"<<"small number is "<<small <<"\n";
return 0;
}
/*
Output -->  

PS F:\Cpp_programes\.vscode\cppTasks\day_1> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ smalLarge.cpp -o smalLarge } ; if ($?) { .\smalLarge }     

large numbere is  9 
small number is 1

*/