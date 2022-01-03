#include <bits/stdc++.h>
using namespace std;

bool primefact(int n)
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void getprimefact(int n)
{
    vector<int> fact;
    int high = n;
    for (int i = 2; i * i < high; i++)
    {
        while (n % i == 0)
        {
            fact.push_back(i);
            n /= i;
        }
    }

    if (fact.empty())
    {
        cout <<high<< " is prime number";

    }
    if(n!=0){
        fact.push_back(n);
    }
    for (int ele : fact)
    {
        cout << ele << " ";
    }
}

int gcd(int a, int b)
{
    if (b > a)
    {
        swap(a, b);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(a%b, b);
}
int main()
{

    // int n = 17;
    // cout<<primefact(n)<<" \n";

    int a = 100, b = 26;
    cout << (a) << " : ";
    getprimefact(a);
    cout << "\n"
         << b << " : ";
    getprimefact(b);
    cout << "\n";
    cout <<"gcd --->  "<< gcd(a, b);

    return 0;
}