#include <bits/stdc++.h>
using namespace std;
void solve()
{int n;
    cin>>n;
    int a[3][3];

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin>>a[i][j];
        }
    }

    int total_moves = 0;
    int curr_moves = 0;

    //Type-1 move
    //Red-Blue
    curr_moves = min(a[0][2], a[2][0]);
    a[0][2] -= curr_moves;
    a[2][0] -= curr_moves;
    a[0][0] += curr_moves;
    a[2][2] += curr_moves;
    total_moves += curr_moves;

    //Blue-Green
    curr_moves = min(a[1][2], a[2][1]);
    a[1][2] -= curr_moves;
    a[2][1] -= curr_moves;
    a[1][1] += curr_moves;
    a[2][2] += curr_moves;
    total_moves += curr_moves;
    
    //Red-Green
    curr_moves = min(a[0][1], a[1][0]);
    a[0][1] -= curr_moves;
    a[1][0] -= curr_moves;
    a[0][0] += curr_moves;
    a[1][1] += curr_moves;
    total_moves += curr_moves;

    //Type-2 moves
    total_moves += 2*(a[0][1] + a[0][2]);
    cout<<total_moves;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}