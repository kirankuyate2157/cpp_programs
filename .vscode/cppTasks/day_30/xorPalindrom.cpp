#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // for (int x : v)
        //     cout << x << ",";
        // cout << "\n";

        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int r = n - 1; r > 0; r--)
            {
                if (arr[i] & arr[r] == 0)
                {
                    cout << "(" << arr[i] << "," << arr[r] << "), ";
                    i++;

                    continue;
                }
                else
                {
                    if (arr[i] > arr[r])
                    {
                        // cout<<"("<<arr[i]<<","<<arr[r]<<"), ";
                        swap(arr[i], arr[r]);
                        for (int k = 0; k < n; k++)
                            cout << arr[k] << ",";
                        cout << "\n";
                        cnt++;
                        i++;
                        r--;
                    }
                    else
                    {
                        i++;
                        continue;
                    }
                }
            }
        }
        // for(int x:arr)cout<<x<<",";
        cout << "\n";
        if (cnt != 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
/*
int gcd(int a, int b)
{
    if (b > a)
    {
        swap(a, b);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(a%b, b);
}
int main(){
int t;cin>>t;
while(t--){
    int n,m;cin>>n>>m;

}

    return 0;
}

i=1
6 34 4 24 1 9
1 34 4 24 6 9

i=2
1 9 4 24 6 34
1 6 4 24 9 34
1 4 6 24 9 34

i=3
...
i=4
1 4 6 9 24 34











*/