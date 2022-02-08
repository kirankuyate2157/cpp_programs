#include <bits/stdc++.h>
using namespace std;
bool ispos(int row, int col, vector<string> &v, int n){
    int r = row,c = col;
    while (c >= 0){
        if (v[r][c] == 'Q')
            return false;
        c--;
    }
    r = row,c = col;
    while (r >= 0 && c >= 0){
        if (v[r][c] == 'Q')
            return false;
        r--, c--;
    }
    r = row, c = col;
    while (r < n && c >= 0){
        if (v[r][c] == 'Q')
            return false;
        r++, c--;
    }
    return true;
}
void queens(int col, vector<string> &v, vector<vector<string>> &ans, int n){
    if (col == n){
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < n; i++){
        if (ispos(i, col, v, n)){
            v[i][col] = 'Q';
            queens(col + 1, v, ans, n);
            v[i][col] = '.';
        }
    }
}
//optimized 
void Queens(int col, vector<string> &v, vector<vector<string>> &ans, vector<int> &lrow, vector<int> &upperDiag, vector<int> &lowDiag, int n){
    if (col == n){
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < n; i++){
        if (lrow[i] == 0 && upperDiag[n - 1 + col - i] == 0 && lowDiag[i + col] == 0){
            v[i][col] = 'Q';
            lrow[i] = 1;
            upperDiag[n - 1 + col - i] = 1;
            lowDiag[i + col] = 1;
            Queens(col + 1, v, ans, lrow, upperDiag, lowDiag, n);
            
            v[i][col] = '.';
            lrow[i] = 0;
            upperDiag[n - 1 + col - i] = 0;
            lowDiag[i + col] = 0;
            
        }
    }
}
int main(){
    int n = 10;
    vector<string> v(n);
    string s(n, '.');

    for (int i = 0; i < n; i++){
        v[i] = s;
    }
    vector<vector<string>> ans;
    // queens(0, v, ans, n);
    vector<int> lrow(n, 0);
    vector<int> upperDiag(2*n-1, 0);
    vector<int> lowDiag(2*n-1, 0);
    Queens(0, v, ans, lrow, upperDiag, lowDiag, n);
    for (auto y : ans){
        for (auto x : y){
            for(char c:x)cout << c<< " ";
            cout<<"\n";
        }
        cout << "\n";
    }
    return 0;
}