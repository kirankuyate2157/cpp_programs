#include <iostream>
using namespace std;

int rotate(int arr[], int n, int d)
{
    for (int j = 0; j < d; j++)
    {
        int temp = arr[0];
        for (int i = 1; i < n; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[n - 1] = temp;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        int d;
        cin >> d;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            
        }
        rotate(arr, n, d);
        display(arr, n);
        cout << "\n";
    }
}

// #include <iostream>
// using namespace std;

// void leftrotate(int arr[],int d,int n){
//     // if(n==0){
//     //     return;
//     // }
//     int temp=arr[0];
//     for(int i=0;i<d;i++){

//     arr[i]=arr[i+1];
//     arr[n-1]=temp;
// }}

// void display(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<"\n";
//     }
// }

// int main() {
// int t;
// cin>>t;
// for(int i=0;i<t;i++){
//     int n,d;
//     cin>>n>>d;
//     int arr[n];
//     for(int j=0;j<n;j++){
//         cin>>arr[i];
//     }
//     leftrotate(arr,d,n);
//     display(arr,n);
// }
// 	return 0;
// }