#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
void  pascal(int n)
{
    vector<vector<int>> mat;
    for (int i = 0; i < n; i++)
    {vector<int> v;
        for (int j = 0; j <=i; j++)
        {
             v.push_back(1);
        }
        mat.push_back(v);
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            
            if (i > 0&&j>0)
            {
                mat[i + 1][j]=(mat[i][j-1] + mat[i][j]);
            }
        }
    }
    print(mat);
}


int main()
{
    int n = 5;
    pascal(5);
    // vector<vector<int>> v = pascal(n);
    // print(v);
    return 0;
}