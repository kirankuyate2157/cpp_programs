#include <bits/stdc++.h>
using namespace std;
void DFS(int node,vector<bool>&visited,vector<int>adj[], stack<int>&st){
    visited[node]=true;
    for(auto nbr:adj[node]){
        if(!visited[nbr])
            DFS(nbr,visited,adj,st);
    }
    st.push(node);
}
void revDFS(int cur,vector<bool>&visited,vector<int>transpose[]){
    visited[cur]=true;
    for(auto nbr:transpose[cur]){
        if(!visited[nbr])
            revDFS(nbr,visited,transpose);
    }
}

int kosaRaju(int n,vector<int>adj[]){
    stack<int>st;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i])
            DFS(i,visited,adj,st);
    }
    cout<<"\npssed1\n";
    vector<int>transpose[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        for(auto x:adj[i])
            transpose[x].push_back(i);
    }
    int count=0;
    cout<<"\npssed\n";
    while(!st.empty()){
        int cur=st.top();
        st.pop();
        if(!visited[cur]){
         count++;
         revDFS(cur,visited,transpose);
        }
    }
    return count;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
    cout<<kosaRaju(n, adj);
    // cout<<kosaraju(n,adj);

    return 0;
}