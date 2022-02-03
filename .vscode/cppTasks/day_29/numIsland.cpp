#include<bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        
        return count;
    }
    
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        queue<pair<int,int>> q;
        q.push({i,j});
        
        int m=grid.size();
        int n=grid[0].size();
        
        int dr[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
            int curi=q.front().first;
            int curj=q.front().second;
            q.pop();
            
            if(visited[curi][curj]){
                continue;
            }
            visited[curi][curj]=true;
            
            for(int k=0;k<4;k++){
                int dx=dr[k][0];
                int dy=dr[k][1];
                
                int nbri=curi+dx;
                int nbrj=curj+dy;
                
                if(nbri >= 0 && nbri < m && nbrj >= 0 && nbrj < n && grid[nbri][nbrj]=='1'){
                    q.push({nbri,nbrj});
                }
            }
            
        }
    }
    
    int main(){


        return 0;
    }