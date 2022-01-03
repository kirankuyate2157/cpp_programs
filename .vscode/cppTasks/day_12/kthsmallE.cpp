#include<bits/stdc++.h>
using namespace std;

int  kthsmall(int arr[], int n, int k)
{
    for (int i = 0; i<n; i++)     //insertion sorting
    {
        int cur = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > cur)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }
 return( arr[k - 1]);   //returning kth  smallest element 
}

int main() 
{
int n = 9;
    int arr[] = {6, 8, 22, 56, 9, 176, 7, 13, 5};
int k=4;
cout<<"the smallest elements is ";
cout<<kthsmall(arr,n,k);
return 0;
}