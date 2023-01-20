#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int l = 1;

        for (int i = 1; i <= sqrt(area); i++)
        {
            if (area % i == 0)
                l = i;
        }
        return {area / l, l};
    }
};
int main()
{

    Solution obj;
    vector<int> x = obj.constructRectangle(565);
    cout << "  array [L, W] where L and W are the length and width of the web page you designed in sequence : {" << x[0] << "," << x[1] << "}" << endl;
    return 0;
}