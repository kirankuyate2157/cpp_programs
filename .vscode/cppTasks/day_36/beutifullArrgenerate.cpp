#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> beautifulArray(int N)
    {
        vector<int> res = {1};
        while (res.size() < N)
        { // makinng even odd at one side
            vector<int> tmp;

            for (int i : res)
                if (i * 2 <= N)
                    tmp.push_back(i * 2);

            for (int i : res)
                if (i * 2 - 1 <= N)
                    tmp.push_back(i * 2 - 1);

            res = tmp;
        }
        return res;
    }
};

int main()
{
    vector<int> ans;
    Solution obj;
    int n;
    cout << "size of array do ypu want to  fenerate beutifull  array : ";
    cin >> n;
    ans = obj.beautifulArray(n);
    cout << "[";
    for (auto x : ans)
        cout << x << ", ";
    cout << "]";
    return 0;
}