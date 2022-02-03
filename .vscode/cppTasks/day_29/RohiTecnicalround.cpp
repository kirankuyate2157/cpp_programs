#include <bits/stdc++.h>
using namespace std;
// void isprime(int n)
// {
//     bool flg = true;
//     for (int i = 2; i < n - 1; i++)
//     {
//         if (n % i == 0)
//         {
//             flg = false;
//             break;
//         }
//     }
//     if (flg)
//         cout << "is prime number\n";
//     else
//         cout << "is not prime number\n";
// }
// void alphaTriangle(int n)
// {
//     char x = 'a';
//     for (int k = 1; k < n; k++)
//     {
//         for (int i = n; i > k; i--)
//         {
//             cout << " ";
//         }
//         for (int i = 1; i < k; i++)
//         {
//             cout << (char)(x - 1 + i);
//         }
//         for (int i = 2; i < k; i++)
//         {
//             cout << (char)(x + 1 + i);
//         }
//         cout << "\n";
//     }
// }

// string reverseString(string s)
// {
//     string ans = "";
//     for (int i = s.length(); i >= 0; i--)
//     {
//         ans += s[i];
//     }
//     return ans;
// }
// void swap(int &a, int &b)
// {
//     a = a ^ b;
//     b = a ^ b;
//     a = a ^ b;
// }
// void largestNum(int arr[], int n)
// {
//     int large = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > large)
//         {
//             large = arr[i];
//         }
//     }
//     cout << "large element in the array is  ... " << large << "\n";
// }
// void evenPosEle(int arr[], int n)
// {
//     for (int i = 0; i < n; i += 2)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << "\n";
// }
// int main()
// {
//     // int n;
//     // cin >> n;
//     // isprime(n);
//     // alphaTriangle(n);
//     // string s="rohini";
//     // cout<<reverseString(s);
//     // int a = 4, b = 7;
//     // cout << "a = " << a << "  b =" << b << "\n";
//     // swap(a, b);
//     // cout << "a = " << a << "  b =" << b << "\n";
//     int arr[] = {5, 7, 1, 5, 9, 2, 5, 7, 5, 2, 4, 6, 34, 12, 77, 999, 23};
//     int n = sizeof(arr) / sizeof(int);
//     // largestNum(arr, n);
//     evenPosEle(arr, n);
// }

void solution()
{
    int n, m;
    cin >> n >> m;

    int chance = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (n - m > 0)
        { 
            chance++;
            n /= m;
        }
    }

    cout << chance << "\n";
}
int main()
{

    solution();
    solution();
    solution();

    return 0;
}
