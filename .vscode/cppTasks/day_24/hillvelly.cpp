#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, d;
        cin >> h >> d;
        string s = "";
        if(h==d){
            cout<<"E->";
            for(int i=1;i<h+1;i++){
                s+="01";
            }
        }else if(d>h){

            for(int i=1;i<=h+1;i++){
                s+="10";
            }
            cout<<" G->";
            for(int i=1;i<=d-h-1;i++){
                s+="110";
            }
            s+="1";
        }else{
            for(int i=1;i<=d;i++){
                s+="01";
            }
            cout<<"L->";
            for(int i=1;i<=h-d;i++){
                s+="010";
            }
        }
        cout << s.length() << "\n"
             << s << "\n";
    }
    return 0;
}
/*
3
3 2
2 3
3 3
->
7
0101010
7
1010101
8
01010101
*/