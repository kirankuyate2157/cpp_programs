#include<bits/stdc++.h>
using namespace std;

string ChangeS(string s){  //taking copy of  the string 
    int n=s.length();
    for(int i=0;i<n;i++){                       //if string characters are in lower case then chage into upper case 
        if(s[i]>='a'&& s[i]<='z'){
            s[i]=s[i]-'a'+'A';

        }
       else if (s[i]>='A'&& s[i]<='Z'){         //if  characters are in upper case then change into lower 
            s[i]=s[i]-'A'+'a';
        }
    }
    return s;
}


write a  function which convert lower string to upprer and upper to lower
int main() 
{
string s="KIrank#UYaTE";
cout<<ChangeS(s);
return 0;
}