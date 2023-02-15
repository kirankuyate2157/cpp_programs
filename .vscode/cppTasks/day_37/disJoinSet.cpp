#include <bits/stdc++.h>
using namespace std;
vector<int> Rank;
vector<int> Parent;
void makeStr(int n)
{
    Rank.resize(n + 1);
    Parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        Rank[i] = 0;
        Parent[i] = i;
    }
}
int findPar(int x)
{
    if (x == Parent[x])
        return x;
    return Parent[x] = findPar(Parent[x]);
}
void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (Rank[u] < Rank[v])
        Parent[u] = Parent[v];
    else if (Rank[u] > Rank[v])
        Parent[v] = Parent[u];
    else
    {
        Parent[u] = Parent[v];
        Rank[v]++;
    }
}

int main()
{
    int n;
    cout << "enter size : ";
    cin >> n;

    makeStr(n);
    while (n--)

    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    cout << "enter op exit size : ";
    int x, y;
    cin >> x >> y;
    if (findPar(x) == findPar(y))
        cout << "They belog to same component ..,";
    else
        cout << "They are belogs to seperate components ..,";
    return 0;
}