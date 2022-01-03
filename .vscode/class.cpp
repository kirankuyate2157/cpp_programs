#include<iostream>
using namespace std;
class Sample{


    public:
    int x;  //data memeber which is by default private
    void   print(){
        cout<<"\n Inside the class "<<"\n Member Function of the class";
        cout<<"\nX ="<<x;
    }
};
int main(){

    cout<<"\n Inside main function";
   Sample obj;    // Creating object
cout<<"\n Enter the input data";
cin>>obj.x;
obj.print();

return 0;
}