#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int rowKing, colKing, x1, x2, y1, y2;
        cin >> rowKing >> colKing >> x1 >> y1 >> x2 >> y2;
        string res = "NO";
        if(! (rowKing == 1 || rowKing == 8 || colKing == 1 || colKing == 8))
        {
            res = "NO";
        }
        else
        {
            if (rowKing == 1)
            {
                if ((x1 == 2 || x2 == 2) && y1 != y2)
                {
                    if (abs(y1 - colKing) > 1 && abs(y2 - colKing) > 1)
                    {
                        res = "YES";
                    }
                }
            }
            else if (rowKing == 8)
            {
                if ((x1 == 7 || x2 == 7) && y1 != y2)
                {
                    if (abs(y1 - colKing) > 1 && (y2 - colKing) > 1)
                    {
                        res = "YES";
                    }
                }
            }
            if (colKing == 1)
            {
                if ((y1 == 2 || y2 == 2) && x1 != x2)
                {
                    if (abs(x1 - rowKing) > 1 && abs(x2 - rowKing) > 1)
                    {
                        res = "YES";
                    }
                }
            }
            else if (colKing == 8)
            {
                if ((y1 == 7 || y2 == 7) && x1 != x2)
                {
                    if (abs(x1 - rowKing) > 1 && (x2 - rowKing) > 1)
                    {
                        res = "YES";
                    }
                }
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}

/*
input   ----->
4
1 1
8 2
7 3
1 8
8 2
8 3
1 1
8 2
2 3
1 1
8 8
8 2
 
 output  ----->
YES
NO
NO
NO



You are given a standard 8×8 chessboard which has exactly 3 pieces placed on it - 2 black rooks and 1 white king. The rows are numbered 1 to 8 from bottom to top, and the columns are numbered 1 to 8 from left to right. The cell at the intersection of the i-th column and j-th row is denoted (i,j) (like the coordinate system on the xy

-plane).

Is it possible for the white king to be checkmated by the rooks in exactly one move? It is guaranteed that the initial position of pieces is such that the white king is not under check.

Note that in the given situation, black moves first.

Assume that all the chess rules are to be followed:

    Each square can contain at most one piece.
    Rooks can only travel in straight lines along the row or column they are placed at, and can't jump over other pieces.
    The King can move to any of its 8

adjacent squares.
A piece can't capture a piece of the same color as itself.
After a black makes a move, the white king can capture a rook if it's present on any of the 8

    adjacent squares and not protected by the other rook.
    The king is said to be in checkmate if the king is currently under check and there exists no legal move with the king to escape from the check.
    Stalemate is considered as a draw for both sides.

For a more detailed explanation of the moves of pieces, along with images, please click here.

Note: The input and output are large, so use fast input-output methods.

    In C++, either use printf and scanf, or add the line ios::sync_with_stdio(0); cin.tie(0); to the beginning of main to speed up cin and cout. Also, do not use endl, only use '\n'.
    In python3/pypy3, add the lines

import sys
input = sys.stdin.readline

to the beginning of your code and then use input as you would normally do

    In Java, use BufferedReader and PrintWriter

Input Format

    The first line of input will contain a single integer T

, denoting the number of test cases. The description of T
test cases follows.
Each test case contains three lines of input.
The first line contains two space-separated integers rowKing
and colKing
, the row and column respectively in which white king is placed.
The second line contains two space-separated integers x1
and y1
, the row and column respectively in which the first black rook is placed.
The third line contains two space-separated integers x2
and y2

    , the row and column respectively in which the second black rook is placed.

Output Format

For each test case, output a single line containing the answer: "YES" if it's possible to checkmate the king in one move and "NO" if not.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).
Constraints

    1≤T≤1.6⋅105

1≤xk,yk,x1,y1,x2,y2≤8
Initially the king is not under check, i.e, xk≠x1
and xk≠x2 and yk≠y1 and yk≠y2
.
No two pieces overlap.



*/