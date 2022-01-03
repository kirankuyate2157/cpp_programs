#include<iostream>

int xOcur(int arr[],int n,int x)     
{
    int res=0;                // result
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x){     // is present then count it
            res++;
        }
    }
    return res;
}

using namespace std;
int main(){
  int arr[]={5,2,8,5,4,7,2,5,2,4,2,5};       //array declaration 
  int n=sizeof(arr)/sizeof(int);        //size of array
  int x=5;                        //seaching element
 cout<< xOcur(arr,n,x);      //calling function where it will  return  x occurence in array 

    return 0;
}