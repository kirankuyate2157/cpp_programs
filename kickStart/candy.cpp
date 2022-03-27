#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=1,T;
    cin >> T;
    while (t<=T)
    {
        int N, M;
        cin >> N >> M;
        vector<int> cad(N);
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> cad[i];
            sum += cad[i];
        }
        int rem = sum % M;
        cout << "Case #" << t << ": " << rem << "\n";
        t++;
    }

    return 0;
}