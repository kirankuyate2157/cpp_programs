#include <iostream>
using namespace std;
int main()
// ladder number patterns 
{
    int n = 7;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i+1; j++)
        {
            cout << j << " ";
           
        }
        for (int j = i-1; j >0;j--)
        {
            cout << j << " ";
        }
        cout<<"\n";
    }

    return 0;
}