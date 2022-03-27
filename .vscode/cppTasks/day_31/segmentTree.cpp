#include <bits/stdc++.h>
using namespace std;
int build(int arr[], vector<int> &tree, int l, int r, int index)
{
    if (l > r)
        return 0;
    if (l == r)
        return tree[index] = arr[l];
    int mid = (l + r) / 2;
    return tree[index] = build(arr, tree, l, mid, 2 * index + 1) + build(arr, tree, mid + 1, r, 2 * index + 2);
}

int query(vector<int> tree, int lt, int ht, int l, int h, int index)
{
    if (l > ht || h < lt)
        return 0;
    if (l <= lt && h >= ht)
        return tree[index];
    int mid = (lt + ht) / 2;
    return query(tree, lt, mid, l, h, 2 * index + 1) + query(tree, mid + 1, ht, l, h, 2 * index + 2);
}
void update(vector<int> &tree, int l, int h, int ind, int x, int index)
{
    // if (ind < l || ind > h)
    //     return;
    if (l == h)
    {
        tree[index] = x;
        return;
    }
    int mid = (l + h) / 2;
    if (ind <= mid)
        update(tree, l, mid, ind, x, 2 * index + 1);
    else
        update(tree, mid + 1, h, ind, x, 2 * index + 2);
    tree[index]=tree[2*index+1]+tree[2*index+2];
}

int main()
{

    int arr[] = {4, 2, 8, 2, 9, 23, 11, 7, 4, 6, 12, 34, 15, 1, 3, 5};
    int n = sizeof(arr) / sizeof(int);
    vector<int> tree(4 * n, 0);
    tree[0] = arr[0];
    build(arr, tree, 0, n - 1, 0);
    int i = 0;
    for (auto x : tree)
    {
        cout << i++ << " : " << x << ", ";
    }
    cout << "\n";
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, h;
            cin >> l >> h;
            int ans = query(tree, 0, n - 1, l, h, 0);
            cout << "sum in range " << l << " -> " << h << " is " << ans << "\n";
        }
        else if (type == 2)
        {
            int ind, x;
            cin >> ind >> x;
            update(tree, 0, n - 1, ind, x, 0);
            cout << "Updated...\n";
        }
    }

    cout<<"\n\n\t Ye Dil Mange More ....\n";

    return 0;
}