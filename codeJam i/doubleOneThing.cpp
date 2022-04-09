
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end()); //reverse is liye kiy kiu ki hame minimum string lani hai..
    string ans;
    char last = 0;
    char another_last = 0;
    for (auto ch : s)
    {
        if (ch != last)`                //check last ele if same ignore else prev last ko last kar do.. 
            another_last = last;
        ans += ch;                      //original ele ko addd kar do..                   
        if (ch < another_last)          //or check kro ki ab current char is less than prev so thne se double add kr do..
            ans += ch;
        last = ch;                      //last ko current ke sath update karo ..
    }
    reverse(ans.begin(), ans.end());    //to ham fir se jo original sequence tha use us formate me kar dege..
    cout<<ans<<"\n";
}
int main()
{
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        t++;
    }

    return 0;
}

/*
int main()
{
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        string s;
        cin >> s;
        int n = s.length();
        vector<string> ans;

        set<char> sets;
        for (char ch : s)
            sets.insert(ch);
        set<char, greater<char>>::iterator itr;
        // cout << "\nThe set s1 is : \n";
        for (itr = sets.begin(); itr != sets.end(); itr++)
        {

            int x = *itr - 'A';
            char y = '@';
            string extra = "";
            for (int i = 0; i < n; i++)
            {

                if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
                {
                    // cout << "\nx :" << x << " ";
                    // cout << s[i] - 'A' << " ";
                    if (s[i] - 'A' <= x)
                    {
                        if (s[i]  != y)
                            extra += s[i];
                        y = s[i];
                    }
                    if (s[i] - 'A' < x)
                        x = s[i] - 'A';
                }
            }
            string a1 = "";
            int k1 = 0;
            for (char ch : s)
            {
                a1 += ch;
                if (extra[k1] == ch)
                {
                    a1 += extra[k1++];
                }
            }
            ans.push_back(a1);
        }
        sort(ans.begin(), ans.end());
        // for (auto st : ans)
        // cout << st << ", ";
        cout << "Case #" << t << ": " << ans[0] << "\n";
        t++;
    }

    return 0;
}


*/