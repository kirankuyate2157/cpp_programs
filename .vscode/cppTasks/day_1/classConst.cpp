#include <bits/stdc++.h>
using namespace std;

// A constructor is a special type of member function of a class which initializes objects of a class.
// Types : 
    //  Default constructor is the constructor which doesn’t take any argument. It has no parameters.
    // It is possible to pass arguments to constructors. Typically, these arguments help initialize an object when it is created. 
    //A copy constructor is a member function which initializes an object using another object of the same class. Detailed article on Copy Constructor.

class common
{
    int a;
    int b;
    int entry=0;
    public:
    common(){     //default constructor 
        entry=1;
        a=0;
        b=0;
    } 
    common(int x,int y){        //parametriz constructor..
        a=x; 
        b=y;
    }
    common(common &p){     //copy constructor 
        a=p.a;
        b=p.b;            //copying another object  constructor valuses 
    }
    void display(){
        cout<<a<<"   "<<b<<'\n';
    }
};


int main()
{cout<<"default constructor  \n";
    common o;
    o.display();
    
    
    cout<<" parametriz constructor \n";
    common m(2,3);
    m.display();

    cout<<" cpy constructor \n";
    common n(m);
    n.display();

    return 0;
}
