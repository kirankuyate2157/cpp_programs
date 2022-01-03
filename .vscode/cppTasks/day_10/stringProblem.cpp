#include <iostream>
using namespace std;

void toNumber(string s)
{
    int n = s.length();
    string  res="";
    for (int i = 0; i< n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        { //if character is lies between small case
            res += to_string(s[i] - 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        { //if characteter is lies in upper case
            res += to_string(s[i] - 'A');
        }
        else
        {
          res += s[i];         //when string charecter is numbers,special symboles then directly append to it 
        }
    }
 
    for (int i = 0; i <res.length(); i++)       //prinmting result
    {
        // cout<<s[i]<<" ";
        cout << res[i];
    }
}

int main()
{
    string s ="kiran";
    toNumber(s);

    return 0;
}