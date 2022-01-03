#include<bits/stdc++.h>
using namespace std;
int main() 
{

int arr[]={3,7,1,2,9,3,5,3,6};
int n=sizeof(arr)/sizeof(int);
int large=0;
for(int i=0;i<n;i++){
    if(arr[i]>large){
        large=arr[i];
    }
}

cout<<"large numbere is  "<<large<<"\n";
return 0;
}


/*

Output  --->

PS F:\Cpp_programes> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ largeNum.cpp -o largeNum } ; if ($?) { .\largeNum }
large numbere is  9

*/