#include <bits/stdc++.h>
using namespace std;

void show(priority_queue<int>q){
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<"\n";
}
int minimizedMaximumNumber(int n, int k, vector<int> &a)
{
    // Write your code here.
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
    }
    // show(pq);
    if (pq.empty())
        return 0;
    while (k > 0)
    {
        int max = pq.top();
        pq.pop();
        int x = max / 2;
        pq.push(x);
        pq.push(max - x);
        k--;
        // show(pq);
    }
    return pq.top();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        cout << minimizedMaximumNumber(n, k, arr)<<"\n";
    }
    return 0;
}
