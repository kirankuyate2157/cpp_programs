//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

//Function to count subarrays with sum equal to 0.

ll findSubarray(vector<ll> arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }

    unordered_map<int, int> freq;
    freq[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq.find(arr[i]) != freq.end())
        {
            ans += freq[arr[i]];
        }
        freq[arr[i]]++;
    }
    return ans;
}

// { Driver Code Starts.
int main()
{

    int n = 6;

    vector<ll> arr(n, 0);

    arr ={0,0,5,5,0,0};

    cout << findSubarray(arr, n) << "\n";

    return 0;
} // } Driver Code Ends