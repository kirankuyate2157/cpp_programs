#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (!matrix.size())
            return false;

        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int h = (n * m) - 1;

        while (l <= h)
        {
            int mid = (l + (h - l) / 2);
            if (matrix[mid / m][mid % m] == target)
                return true;
            else if (matrix[mid / m][mid % m] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    Solution obj;
    cout << "Target is found ? : " << obj.searchMatrix(matrix, target) << endl;
    return 0;
}