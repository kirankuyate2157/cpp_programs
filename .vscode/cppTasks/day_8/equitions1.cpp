#include <iostream>
using namespace std;

 int fact(int n)
    {
        int fact = 1;
        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
        }
        return fact;
    }


int main()
{
   

    int n = 2;

    int sum = 0;
    for (int i = 1; i < n; i++)
    {
 
        sum += (i * (i + 2)) / fact(i) + fact(i + 1);
    }
    cout << sum;

    return 0;
}