#include <bits/stdc++.h>
using namespace std;
vector<int> missing_repeated_number(const vector<int> &A)
{
    long long int len = A.size();

    long long int S = (len * (len + 1)) / 2;
    long long int P = (len * (len + 1) * (2 * len + 1)) / 6;
    long long int missingNumber = 0, repeating = 0;
    cout << "S = " << S << endl;
    cout << "P = " << P << endl;
    for (int i = 0; i < A.size(); i++)
    {
        S -= (long long int)A[i];
        P -= (long long int)A[i] * (long long int)A[i];
    }
    cout << "S2 = " << S << endl;
    cout << "P2 = " << P << endl;

    missingNumber = (S + P / S) / 2;
    cout << "miss = " << missingNumber << endl;
    repeating = missingNumber - S;
    cout << "repeating = " << repeating << endl;
    vector<int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 7, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ans = missing_repeated_number(arr);
    for (auto x : ans)
        cout << x << " ";

    return 0;
}