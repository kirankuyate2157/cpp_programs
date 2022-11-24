#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        // int k=0;
        // int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (check(board, i, j, word, n, m))
                    return true;
        return false;
    }

    bool check(vector<vector<char>> &board, int i, int j, string &word, int n, int m)
    {
        if (!word.size())
            return true;

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[0])
            return false;

        char c = board[i][j];
        board[i][j] = '$';
        string s = word.substr(1);
        bool x = check(board, i + 1, j, s, n, m) || check(board, i - 1, j, s, n, m) || check(board, i, j + 1, s, n, m) || check(board, i, j - 1, s, n, m);
        board[i][j] = c;
        return x;
    }
};

int main()
{

    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string s = "ABCCED";
    Solution obj;
    cout << "string is found or not ?\t" << obj.exist(board, s);
    return 0;
}
