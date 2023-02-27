#include <bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
void showNode(Node *root)
{
    if (root->isLeaf)
    {
        cout << "Node " << root->val << ",";
        return;
    }
    showNode(root->topLeft);
    showNode(root->topRight);
    showNode(root->bottomLeft);
    showNode(root->bottomRight);
}

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        return bs(grid, 0, 0, grid.size());
    }

    Node *bs(vector<vector<int>> &grid, int r, int c, int n)
    {
        if (isAllsame(grid, r, c, n))
        {
            return new Node(grid[r][c], true);
        }

        Node *root = new Node(grid[r][c], false);
        root->topLeft = bs(grid, r, c, n / 2);
        root->topRight = bs(grid, r, c + n / 2, n / 2);
        root->bottomLeft = bs(grid, r + n / 2, c, n / 2);
        root->bottomRight = bs(grid, r + n / 2, c + n / 2, n / 2);
        return root;
    }

    bool isAllsame(vector<vector<int>> &grid, int r, int c, int n)
    {
        int a = grid[r][c];
        for (int i = r; i < r + n; i++)
        {
            for (int j = c; j < c + n; j++)
            {
                if (a != grid[i][j])
                    return false;
            }
        }
        return true;
    }
};

int main()
{

    // Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
    // Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
    // The topLeft, bottomLeft and bottomRight each has the same value.
    // The topRight have different values so we divide it into 4 sub-grids where each has the same value.
    // Explanation is shown in the photo below:

    vector<vector<int>> grid = {{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
    Solution obj;
    Node *ans = obj.construct(grid);
    showNode(ans);

    return 0;
}