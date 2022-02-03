
#include <bits/stdc++.h>
using namespace std;

// void setZeroes(vector<vector<int>> &matrix)
// {
//     int row = matrix.size(), col = matrix[0].size();
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 int up = i - 1;
//                 while (up >= 0)
//                 {
//                     if (matrix[up][j] != 0)
//                         matrix[up][j] = -1;
//                     up--;
//                 }
//                 up = i + 1;
//                 while (up < row)
//                 {
//                     if (matrix[up][j] != 0)
//                         matrix[up][j] = -1;
//                     up++;
//                 }
//                 up = j - 1;
//                 while (up >= 0)
//                 {
//                     if (matrix[i][up] != 0)
//                         matrix[i][up] = -1;
//                     up--;
//                 }
//                 up = j + 1;
//                 while (up < col)
//                 {
//                     if (matrix[i][up] != 0)
//                         matrix[i][up] = -1;
//                     up++;
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         for (int j = 0; j < matrix[0].size(); j++)
//         {
//             if (matrix[i][j] <= 0)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }
// void setZeroes(vector<vector<int>> &matrix)
// {

//     int row = matrix.size(), col = matrix[0].size();
//     vector<int> dum1(row, -1), dum2(col, -1);
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 dum1[i] = 0;
//                 dum2[j] = 0;
//             }
//         }
//     }
//     for (int i = 0; i < row; i++)
//         for (int j = 0; j < col; j++)
//             if (dum1[i] == 0 || dum2[j] == 0)
//                 matrix[i][j] = 0;
// }
void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col0, col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = row-1; i >=0; i--)
    {
        for (int j = col-1; j >=0; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }

        if (col0 == 0)
        {
            matrix[i][0] = 0;
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0},
                                  {3, 4, 5, 2},
                                  {1, 3, 1, 5}};

    vector<vector<int>> matrix1 = {{1, 1, 1},
                                   {1, 0, 1},
                                   {1, 1, 1}};
    setZeroes(matrix1);
    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << "\n";
    }
}