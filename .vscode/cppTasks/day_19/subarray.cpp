#include<iostream>
using namespace std;

void subarray(int arr[],int n){
    for(int size=0;size<=n;size++){
        for(int fist=0;fist<n-size+1;fist++){
            for(int i=fist;i<size+fist;i++){
                cout<<arr[i]<<",";
            }
            cout<<"\n";
        }
    }


}
int main(){

int arr[]={1,2,3,4,5};
int n=sizeof(arr)/sizeof(int);
subarray(arr,n);

    return 0;
}