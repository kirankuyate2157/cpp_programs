#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{

    vector<int> visited(26, 0);
    string res = "";
    vector<char> v;
    int n = A.length();
    for (int i = 0; i < n; i++)
    {
        if (!visited[A[i] - 'a'])
        {
            v.push_back(A[i]);
        }
        visited[A[i] - 'a']++;
        bool f = false;
        int m = v.size();
        for (int j = 0; j < m; j++)
        {
            if (visited[v[j] - 'a'] == 1)
            {
                res.push_back(v[j]);
                f = true;
                break;
            }
        }
        if (!f)
        {
            res.push_back('#');
        }
    }
    return res;
}

// string FirstNonRepeating(string A)
// {

//     string s = "";
//     map<char, int> map;
//     char prev = A[0];
//     for (char c : A)
//     {
//         int hash = 0;
//         bool flag = false;
//         if (map.find(c) != map.end())
//         {
//             map[c]++;
//             if (map[c] == 1)
//             {
//                 flag = true;
//             }
//             else
//             {
//                 hash = 1;
//             }
//         }

//         else
//         {
//             map[c]++;
//             flag = true;
//         }

//         int i = 0;
//         while (i < s.length())
//         {
//             if (map[A[i]] == 1 && prev != 1)
//             {
//                 prev = A[i];
//                 // cout << A[i] << " : " << map[A[i]] << " ";
//                 break;
//             }
//             i++;
//         }

//         if (flag)
//         {
//             if (map[prev] == 1)
//             {
//                 s.push_back(prev);
//             }
//             else
//             {
//                 s.push_back(c);
//                 prev = c;
//             }
//         }

//         if (hash == 1)
//         {
//             if (map[prev] == 1)
//             {
//                 s.push_back(prev);
//             }
//             else
//             {
//                 s.push_back('#');
//             }
//         }
//     }

//     return s;
// }

int main()
{

    string s = "pqimpqysf";

    cout << "\n"
         << FirstNonRepeating(s);
    return 0;
}