#include <bits/stdc++.h>
using namespace std;
void setZero(vector<vector<int>> &matrix)
{   int col0=1;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {   if(matrix[i][0]==0)col0=0;
        for (int j = 1; j < n; j++)
        {
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }

        }
    }
    for (int i = m-1; i >=0; i--)
    {   
        for (int j =n-1; j >=1; j--)
        {
            if(matrix[i][0]==0||matrix[0][j]==0){
                matrix[i][j]=0;
        
            }

        }
        if(col0==0)matrix[i][0]=0;
    }
    
}

void print(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    // vector<vector<int>> v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> v = {{0, 1, 2, 0},
                             {3, 4, 5, 2},
                             {1, 3, 1, 5}};

    setZero(v);
    print(v);
    return 0;
}