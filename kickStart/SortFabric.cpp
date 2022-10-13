#include <bits/stdc++.h>
using namespace std;
struct node
{

    string color;
    int D;
    int U;
};
bool static comp(struct node *a, struct node *b)
{
    if ((a->color[0] - '0') <= (b->color[0] - '0'))
        return true;
    if (a->D <= b->D)
        return true;
    return a->U <= b->U;
    ;
}

int main()
{
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        int n;
        cin >> n;
        struct node *arr[n];
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i]->color >> arr[i]->D >> arr[i]->U;
        }
        sort(arr, arr + n, comp);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i]->color << " " << arr[i]->D << " " << arr[i]->U << "\n";
        }
        cout << cnt << "000 \n";
        t++;
    }
    return 0;
}