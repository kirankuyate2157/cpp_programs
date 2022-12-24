
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

vector<int> tree[200001];
ll subtreeAns[200001];
ll ans[200001];
int subtreeSize[200001];
class Solution {
public:
    vector<vector<int>> v;
    vector<int> counter, res;
        
    void dfs(int i, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            dfs(u, i);
            counter[i] += counter[u];
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }

    void dfs2(int i, int n, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            res[u] = res[i] - counter[u] + n - counter[u];
            dfs2(u, n, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        dfs(0);
        dfs2(0, n);
        return res;
    }
};
void preprocessing(int src, int par)
{
    int numOfNodes = 1;
    ll ansForSubtree = 0;
    for (int child : tree[src])
    {
        if (child != par)
        {
            preprocessing(child, src);
            numOfNodes += subtreeSize[child];
            ansForSubtree += subtreeSize[child] + subtreeAns[child];
        }
    }
    subtreeSize[src] = numOfNodes;
    subtreeAns[src] = ansForSubtree;
}

void solve(int src, int par, ll par_ans, int &totalNodes)
{
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));

    for (int child : tree[src])
    {
        if (child != par)
            solve(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
    }
}

int main()
{
    fast_io;
    ll t, n, m, x, i, j, k, q;
    // cin >> t;
    t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        fr(0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        preprocessing(1, 0);
        solve(1, 0, 0, n);
        fr(1, n + 1)
        
                cout
            << ans[i] << ' ';
    }
    return 0;
}
