#include <iostream>
using namespace std;
#define ll long long
long long k[200005];
long long x = 0;
long long k2[200005];
long long y = 0;
void take1(long long a, long long b)
{
    k[x++] = a;
    k[x++] = b;
}
void take2(long long a, long long b)
{
    k2[y++] = a;
    k2[y++] = b;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        x == y == 0;
        ll cnt1 = 0;
        ll cnt2 = 0;
        ll n;
        cin >> n;
        ll A[n];
        ll B[n];
        ll U = 0, u = 0;
        ll V = 0, v = 0;
        ll checkOdd = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> A[i];
            B[i] = A[i];
        }
        if (A[0] % 2 == 0)
        {
            if (A[1] % 2 == 1)
            {
                for (ll i = 2; i < n; i++)
                {
                    if (A[i] % 2 == 1)
                    {
                        U = A[i];
                        V = i;
                        checkOdd++;
                        A[1] = A[1] ^ U;
                        cnt1++;
                        take1(1, U);
                        break;
                    }
                }
            }
            else
            {
                U = A[1];
                V = 1;
                checkOdd = 1;
            }
            u = A[1];
            v = 1;
            for (ll i = 2; i < n; i++)
            {
                if (A[i] % 2 == 1)
                {
                    A[i] = A[i] ^ u;
                    cnt1++;
                    take1(i, v);
                }
                i++;
                if (i < n)
                {
                    if (A[i] % 2 == 0)
                    {
                        A[i] = A[i] ^ u;

                        cnt1++;
                        take1(i, v);
                    }
                }
            }
            B[0] = B[0] ^ U;
            cnt2++;
            take2(0, U);
            u = B[0];
            v = 0;
            for (ll i = 1; i < n; i++)
            {
                if (B[i] % 2 == 1)
                {
                    B[i] = B[i] ^ u;
                    cnt2++;
                    take1(i, v);
                }
                i++;
                if (i < n)
                {
                    if (B[i] % 2 == 0)
                    {
                        B[i] = B[i] ^ u;

                        cnt2++;
                        take2(i, v);
                    }
                }
            }
        }
        else
        {

            checkOdd = 1;
            u = B[0];
            v = 0;
            for (ll i = 1; i < n; i++)
            {
                if (B[i] % 2 == 0)
                {
                    B[i] = B[i] ^ u;
                    cnt2++;
                    take2(i, v);
                }
                i++;
                if (B[i] % 2 == 1 && i < n)
                {
                    A[i] = A[i] ^ u;
                    cnt2++;
                    take2(i, v);
                }
            }
            B[0] = B[0] ^ B[1];
            cnt2++;
            take2(0, 1);
        }
        if (checkOdd == 0)
        {
            cout << "-1\n";
        }
        else if (cnt1 > cnt2)
        {
            ll j;
            cout << cnt2 << "\n";
            for (ll i = 0; i < cnt2; i++)
            {
                j = i * 2;
                cout << k2[j] + 1 << " " << k2[j + 1] + 1 << "\n";
            }
        }
        else
        {
            int j;
            cout << cnt1 << "\n";
            for (ll i = 0; i < cnt1; i++)
            {
                j = i * 2;
                cout << k[j] + 1 << " " << k[j + 1] + 1 << "\n";
            }
        }
    }

    return 0;
}
