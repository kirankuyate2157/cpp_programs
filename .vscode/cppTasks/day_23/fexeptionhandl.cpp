#include<iostream>

using namespace std;
void function(int num)
{
    try
    {
        if (num)
                  throw num;
         else throw "Value is zero";
    }
    //multipe catch for single try block
    catch (int i)
    {
        cout <<"Exception for number is handled:"<<i<<"\n";
    }
        catch(const char*str)
    {
        cout<<"Exception for string is handled:";
        cout<<str<<"\n";
    }
}
int main()
{
        cout <<"start"<<endl;
        function(0);//As value of num is 'not true' else part will         
        function (1);// be expected
        function (2);
        function (3);
        cout <<"End"<<endl;
        return 0;
}