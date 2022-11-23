#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        set<string> s;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    string a = "r" + to_string(i) + board[i][j];
                    string b = "c" + to_string(j) + board[i][j];
                    string c = "b" + to_string((i / 3) * 3 + (j / 3)) + board[i][j];
                    if (s.find(a) == s.end() && s.find(b) == s.end() && s.find(c) == s.end())
                    {
                        s.insert(a);
                        s.insert(b);
                        s.insert(c);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        sudku(board);
    }

    bool sudku(vector<vector<char>> &box)
    {
        int n = box.size();
        int m = box[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (box[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(i, j, c, box) == true)
                        {
                            box[i][j] = c;

                            if (sudku(box) == true)
                                return true;
                            else
                                box[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(int i, int j, char c, vector<vector<char>> &box)
    {
        for (int k = 0; k < 9; k++)
        {
            if (box[k][j] == c)
                return false;
            if (box[i][k] == c)
                return false;
            if (box[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c)
                return false;
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> box = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << "sudoku is valid" << endl;
    Solution obj;
    int x = obj.isValidSudoku(box);
    if (x)
    {
        obj.solveSudoku(box);
        cout << "sudoku is valid 🙌🙌🤗✅🔥🥂 :\n\n";
        for (int i = 0; i < 9; i++)
        {
            for (auto c : box[i])
            {
                cout << c << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "sudoku is not valid!!!🥺🥺🥺🥺";
    }
    return 0;
}