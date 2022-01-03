#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int b, arr[200] = {0};
        cin >> b;
        arr[0] = 1;
        int i = 1, m = 1, index = 0, temp = 0, x;
        while (i <= b)
        {
            int k = m;
            index = 0;
            while (k--)
            {
                x = arr[index] * i + temp;
                arr[index] = x % 10, temp = x / 10, index++;
            }
            while (temp != 0)
            {
                arr[index] = temp % 10;
                temp = temp / 10;
                index++, m++;
            }
            i++;
        }
        while (m--)
            cout << arr[m];
        cout << endl;
    }
    // your code goes here
    return 0;
}
