#include <bits/stdc++.h>
#include "linkedlist.txt"
using namespace std;

template <class T>
class myStack
{
    linkedlist<T> top;
    int Size;
    string anything;

public:

    myStack()
    {
        Size = 0;
    }

    myStack(string s)
    {
        cout << s << " hii ,i have maded this stack   .....\n";
        Size = 0;
        anything = s;
    }

    void push(T data)
    {
        top.insertAtHead(data);
        Size++;
    }

    void pop()
    {
        top.delethead();
        Size--;
    }

    T mosttop()
    {
        return top.getheadData();
    }
    int size(){
        return Size;
    }
    void showstack()
    {
        top.display();
    }


};

int main()
{

    myStack<int> st;
    st.push(12);
    // st.push(14);
    st.push(16);
    // st.push(16);
    st.push(17);
    // cout<<st.mosttop()<<" ";
    st.pop();
    // cout<<st.mosttop()<<" ";
    st.push(20);
    st.push(18);    st.pop();
    st.push(19);
    st.showstack();
    cout<<" \n"<<st.size()<<"   ";

    return 0;
}

