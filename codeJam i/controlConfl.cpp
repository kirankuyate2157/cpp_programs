#include <iostream>
#include <climits>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool cp2(long long x1, long long x2)
{
    return x1 > x2;
}
bool cp1(long long x1, long long x2)
{
    return x1 < x2;
}

long long mod(long long x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return -1 * x;
    }
}

long long myMinSum = LLONG_MAX;
void giveme(vector<long long> mat, long long N, long long P, long long i)
{
    if (i == N)
    {

        long long sum = mat[0][0];
        for (long long i = 0; i < N; i++)
        {
            for (long long j = 0; j < P - 1; j++)
            {
                sum += mod(mat[i][j + 1] - mat[i][j]);
            }
            if (i != (N - 1))
            {
                sum += mod(mat[i + 1][0] - mat[i][P - 1]);
            }
            // cout<<"subsum="<<sum<<endl;
        }

        // cout<<"sum="<<sum<<endl;

        if (sum < myMinSum)
        {
            myMinSum = sum;
        }
    }
    else
    {
        sort(mat[i].begin(), mat[i].end() + P, cp1);
        giveme(mat, N, P, i + 1);

        sort(mat[i].begin(), mat[i].end() + P, cp2);
        giveme(mat, N, P, i + 1);
    }
}

int main()
{

    long long T;
    cin >> T;

    int t = 1;
    while (T--)
    {
        long long N, P;
        cin >> N >> P;

        vector<long long> mat(N, vector<long long>(P, 0));

        for (long long i = 0; i < N; i++)
        {

            for (long long j = 0; j < P; j++)
            {
                cin >> mat[i][j];
            }
        }

        myMinSum = LLONG_MAX;
        giveme(mat, N, P, 0);
        cout << "Case #" << t << ": " << myMinSum << endl;
        t++;
    }

    return 0;
}