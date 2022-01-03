#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
        #----- Suaduo Code  -------#   

1.make class of particuler name
2.creat data membere
3.define constructon in class
     it may be urenary or biunary
4.and then  define the member function  of opretor (- ,+,/,*) then taking inputes it may be object or any data tipe which we wan perform opration...
5. return type of oprator fin is object 
6. print  data 
  #in drive code
7.create object of oparamds which you wan perform 
then apply membere function on to this objects 
   eg.    obj A  & obj B  ,obj   C=A+B or A-B or A*B ........
8.then it will print or return your result 
 THE ARATHEMATIC equation  add two equation 
 that tiem it will useful...
 in complex number there also it will work...


*/


class test
{
    int a, b;

public:
    test(int x = 0, int y = 0)
    {
        a = x;
        b = y;
    }

    test operator-(test t)
    {
        test temp;
        temp.a = a - t.a;
        temp.b = b - t.b;
        return temp;
    }

    void display()
    {
        cout << a;
        cout << "-" << b<<"i" ;
    }
};

int main()
{
    test x, y, z;
    y = test(2, 4);
    x = test(3, 6);
    z = x - y;

    z.display();

    return 0;
}