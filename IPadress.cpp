#include <bits/stdc++.h>
#include<string>
using namespace std;
#define input freopen("input.text","r",stdin),freopen("output.text",'w',stdout)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
bool isValidIP(string s)
{
    if (s.length() > 3)
    {
        return false;
    }
    if (s.front() == '0' and s.length() > 1)
    {
        return false;
    }
//    long long int val =stoll(s);
//     return val >= 0 and val <= 255;
return true;
}

void IPaddres(string &s, vector<string> ans)
{
    for (long long int i = 0; i < 3 and i < s.length(); i++)
    {
        string first = s.substr(0, i);
        if (isValidIP(first))
        {
            for (long long int j = 1; j < 3 and i + j < s.length(); j++)
            {
                string second = s.substr(i, j);
                if (isValidIP(second))
                {
                    for (long long int k = 1; k <= 3 and i + j < s.length(); k++)
                    {
                        string third =s.substr(i + j, k);
                        string four = s.substr(i + j + k);
                        if (isValidIP(third) and isValidIP(four))
                        {
                            ans.emplace_back(first + "." + second + "." + third + "." + four);
                        }
                    }
                }
            }
        }
    }
    
}

int main(){
// fast;
// input;
    string s = "178452124";
    vector<string> ans;
    IPaddres(s, ans);
    for(auto i:ans){

    
    cout<<i<<"\n";
    }
    return 0;
}