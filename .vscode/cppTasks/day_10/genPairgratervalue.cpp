#include <iostream>
using namespace std;

void pairwithgreaterNum(string s)
{
    int n = s.length();     //length of string 
    string res = "";           //empty string
    for (int i = 0; i < n; i += 2)
    {
        if (s[i] > s[i + 1])     //when charecter is grater add first
        {
            res += s[i];
        }
        else
        {
            res += s[i + 1];      //add second
        }
    }
    for(int i=0;i<res.length();i++){      //printing result string
        cout<<res[i];
    }
}

int main()
{
    string s = "electronics";       //declaring string 
    pairwithgreaterNum(s);        //calling function

    return 0;
}