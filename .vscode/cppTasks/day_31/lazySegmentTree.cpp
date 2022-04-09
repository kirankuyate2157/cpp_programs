#include <bits/stdc++.h>
using namespace std;
// Segmate Tree  (lazy method)
//    - build tree 
//    - query sum 
//    - range  update

int build(vector<int> &tree, int l, int h, int arr[], int index)
{
    if (l > h)
        return 0;
    if (l == h)
        return tree[index] = arr[l];

    int mid = (l + h) / 2;
    return tree[index] = build(tree, l, mid, arr, 2 * index + 1) + build(tree, mid + 1, h, arr, 2 * index + 2);
}
int query(vector<int> &tree, vector<int> &lazy, int lt, int ht, int l, int h, int index)
{
     if(l > ht || h < lt || lt > ht)return 0;
    
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index] * (ht - lt + 1);
        tree[2 * index + 1] += lazy[index];
        tree[2 * index + 2]+= lazy[index];
        lazy[index] = 0;
    }
    if (l <= lt && h >= ht)
        return tree[index];
    int mid = (lt + ht) / 2;
    return query(tree, lazy, lt, mid, l, h, 2 * index + 1) + query(tree, lazy, mid + 1, ht, l, h, 2 * index + 2);
}



void update(vector<int> &tree, vector<int> &lazy, int lt, int ht, int l, int h, int x, int index)
{
    if(l > ht || h < lt || lt > ht)return;
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index] * (ht - lt + 1);
        tree[2 * index + 1] += lazy[index];
        tree[2 * index + 2] += lazy[index];
        lazy[index] = 0;
    }
    if (l <= lt && h >= ht)
    {
        tree[index] += x * (ht - lt+ 1);
        lazy[2 * index + 1] += x;
        lazy[2 * index + 2] += x;
    }
    else
    {
        int mid = (lt + ht) / 2;
        update(tree, lazy, lt, mid, l, h, x, 2 * index + 1);
        update(tree, lazy, mid + 1, ht, l, h, x, 2 * index + 2);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
}

int main()
{
    int arr[] = {6, 2, 5, 1, 8, 9, 12, 6, 15, 27, 19, 31, 94, 11, 43, 2, 9, 66, 3};
    int n = sizeof(arr) / sizeof(int);
    vector<int> tree(4 * n, 0), lazy(4 * n, 0);
    build(tree, 0, n - 1, arr, 0);
    for (int x : tree)
        cout << x << " ,";
    cout << "\n\n";
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
            int ans = query(tree, lazy, 0, n - 1, l, h, 0);
            cout << "sum of range " << l << "  " << h << " is  " << ans << "\n";
        }
        else if (type == 2)
        {
            int l, h, x;
            cin >> l >> h >> x;
            update(tree, lazy, 0, n - 1, l, h, x, 0);
            cout << "updated...\n";
        }
    }
    return 0;
}