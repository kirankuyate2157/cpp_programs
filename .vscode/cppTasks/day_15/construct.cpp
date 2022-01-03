#include <iostream>
using namespace std;
class college
{

public:
    int x = 10;
    int y = 20;
    int z = 30;

    college()
    {
        
        cout << "default constructor is called";
        cout << x << " " <<y<<" ";
    }
   
};

int main()
{

    college matoshri();
    cout<<matoshri;
    return 0;
}