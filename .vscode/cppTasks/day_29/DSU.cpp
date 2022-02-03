#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
        int *leader;
        int *rank;

    public:

        DSU(int n){
            leader=new int[n];
            rank=new int[n];

            for(int i=0;i<n;i++){
                leader[i]=-1;
                rank[i]=1;
            }
        }

        int find(int x){
            if(leader[x]==-1){
                return x;
            }
            return leader[x]=find(leader[x]);
        }

        void merge(int a,int b){
            int ca=find(a);
            int cb=find(b);

            if(ca != cb){
                if(rank[ca] > rank[cb]){
                    leader[cb]=ca;
                    rank[ca]+=rank[cb];
                }else{
                    leader[ca]=cb;
                    rank[cb]+=rank[ca];
                }
            }
        }
};

void krushkals(vector<pair<int,pair<int,int>>> edges,int n){
    DSU dsu(n);
    vector<pair<int,pair<int,int>>> mstEdge;

    sort(edges.begin(),edges.end());
    
    for(int i=0 ; mstEdge.size() < n-1 ;i++){
        pair<int,pair<int,int>> curEdge=edges[i];
        int w=curEdge.first;
        int u=curEdge.second.first;
        int v=curEdge.second.second;

        if(dsu.find(u) == dsu.find(v)){
            continue;
        }
        mstEdge.push_back(curEdge);
        dsu.merge(u,v);
    }
    
    for(auto x:mstEdge){
        int w=x.first;
        int u=x.second.first;
        int v=x.second.second;
        cout<<u<<"->"<<v<<" with weight: "<<w<<"\n";
    }
    cout<<"\n";
}

int main(){
    int n,e;
    cout<<"Enter the number of nodes and edges in your graph:\n";
    cin>>n>>e;
    vector<pair<int,pair<int,int>>> edges;

    cout<<"Enter the edges of your graph\n";
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }

    krushkals(edges,n);
    return 0;
}