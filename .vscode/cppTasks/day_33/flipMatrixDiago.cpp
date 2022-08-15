#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f1(n) for (int i = 0; i < n; i++)
#define f2(m) for (int j = 0; j < m; j++)

void takeMat(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void print(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void rotate(vector<vector<int>> &matrix, bool flg)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    if (flg)
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m, ans = true;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m, 0));
        vector<vector<int>> B(n, vector<int>(m, 0));
        if (n == 1 || m == 1)
        {
            takeMat(A, n, m);
            takeMat(B, n, m);
            f1(n)
            {
                f2(m)
                {
                    if (A[i][j] != B[i][j])
                    {
                        ans = false;
                        break;
                    }
                }
            }
        }
        else
        {
            int x;
            map<int, int> m1, m2, m3, m4;
            f1(n)
            {
                f2(m)
                {
                    cin >> x;
                    if ((i + j) % 2 != 0)
                    {
                        if (m1.find(x) == m1.end())
                        {
                            m1.insert({x, 1});
                        }
                        else
                        {
                            m1.insert({x, m1[x] + 1});
                        }
                    }
                    else
                    {
                        if (m2.find(x) == m2.end())
                        {
                            m2.insert({x, 1});
                        }
                        else
                        {
                            m2.insert({x, m2[x] + 1});
                        }
                    }
                }
            }
            f1(n)
            {
                f2(m)
                {
                    cin >> x;
                    if ((i + j) % 2 != 0)
                    {
                        if (m3.find(x) == m3.end())
                        {
                            m3.insert({x, 1});
                        }
                        else
                        {
                            m3.insert({x, m3[x] + 1});
                        }
                    }
                    else
                    {
                        if (m4.find(x) == m4.end())
                        {
                            m4.insert({x, 1});
                        }
                        else
                        {
                            m4.insert({x, m4[x] + 1});
                        }
                    }
                }
            }

            for (auto ele : m1)
                cout << ele.first << ":" << ele.second << ", ";
            for (auto ele : m2)
                cout << ele.first << ":" << ele.second << ", ";
            cout << endl;
            for (auto ele : m3)
                cout << ele.first << ":" << ele.second << ", ";
            for (auto ele : m4)
                cout << ele.first << ":" << ele.second << ", ";
            for (auto ele : m1)
            {
                if (ele.second != m3[ele.first])
                {
                    ans = false;
                    break;
                }
            }
            for (auto ele : m2)
            {
                if (ele.second != m4[ele.first])
                {
                    ans = false;
                    break;
                }
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
