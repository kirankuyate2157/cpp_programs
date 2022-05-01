
#include <bits/stdc++.h>
using namespace std;
void show(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << " " << *it;
    // cout << '\n';
}

int main()
{
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        int n, cnt = 0;
        cin >> n;
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        int val = 0;
        while (!dq.empty())
        {

            if (dq.back() >= dq.front())
            {
                if (dq.back() >= val)
                {
                    show(dq);
                    val = dq.back();
                    cout << "   val : " << val << " \n";
                    dq.pop_back();
                    cnt++;
                }
                else if (dq.front() >= val)
                {
                    show(dq);
                    val = dq.front();
                    cout << "    val : " << val << " \n";
                    dq.pop_front();
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            else if (dq.back() <= dq.front())
            {
                // cout << val << " ";
                if (dq.back() >= val)
                {
                    show(dq);
                    val = dq.back();
                    cout << "   val : " << val << " \n";
                    dq.pop_back();
                    cnt++;
                }
                else if (dq.front() >= val)
                {
                    show(dq);
                    val = dq.front();
                    cout << "   val : " << val << " \n";
                    dq.pop_front();
                    cnt++;
                }
                else
                {
                    break;
                }
            }
        }
        cout << "Case #" << t << ":";
        cout << cnt << "\n";
        t++;
    }
    return 0;
}

/**

#include <bits/stdc++.h>
using namespace std;
void panCake(vector<int> arr)
{
    int head = 0;
    int tail = arr.size() - 1;
    int max = min(arr[head], arr[tail]), count = 0;
    while (head <= tail)
    {
        if (arr[head] < arr[tail])
        {
            if (max <= arr[head])
            {
                count++;
                max = arr[head];
            }
            head++;
        }
        else
        {
            if (max <= arr[tail])
            {
                count++;
                max = arr[tail];
            }
            tail--;
        }
    }
    cout << count << "\n";
}

int main()
{
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        cout << "Case #" << t << ":";
        panCake(arr);
        t++;
    }

    return 0;
}

 */