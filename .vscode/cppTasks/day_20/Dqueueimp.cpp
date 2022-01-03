
#include <iostream>
using namespace std;

template <class T>
class dqueue
{
    T *arr;
    int N = 10;
    int front, rear;

public:
    dqueue()
    {
        arr = new T(N);
        front = rear = -1;
    }

    void push_front(int key)
    {
        if (full())
        {
            cout << "OVERFLOW\n";
        }
        else
        {
            //If queue is empty
            if (front == -1)
                front = rear = 0;

            //If front points to the first position element
            else if (front == 0)
                front = N - 1;

            else
                --front;

            arr[front] = key;
        }
    }
    void push_back(int key)
    {
        if (full())
        {
            cout << "OVERFLOW\n";
        }
        else
        {
            //If queue is empty
            if (front == -1)
                front = rear = 0;

            //If rear points to the last element
            else if (rear == N - 1)
                rear = 0;

            else
                ++rear;

            arr[rear] = key;
        }
    }

    void pop_front()
    {
        if (empty())
        {
            cout << "UNDERFLOW\n";
        }
        else
        {
            //If only one element is present
            if (front == rear){
                front = rear = -1;}
            else if (front == N - 1) {           //If front points to the last element
                front = 0;}
            else{
                ++front;}
        }
    }

    void pop_back()
    {
        if (empty())
        {
            cout << "UNDERFLOW\n";
        }
        else
        {
            if (front == rear)         //If only one element is present
                front = rear = -1;
            else if (rear == 0)     //If rear points to the first position element
                rear = N - 1;
            else
                --rear;
        }
    }

    bool empty()
    {
        if (front == -1 || rear == -1)     //both pointing to -1 it means queue is empty 
            return true;
        else
            return false;
    }

    bool full()
    {
        if ((front == 0 && rear == N - 1) || (front == rear + 1))      //when  front at first position & rear at the end it means queue is full or in circuler array front crosses the rear means queue is full...
            return true;
        else
            return false;
    }

    T get_front()
    {
        if (empty())
        {
            cout << "f=" << front << endl;
            cout << "UNDERFLOW\n";
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    T get_back()
    {
        if (empty())
        {
            cout << "UNDERFLOW\n";
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }


    void display()
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i <= N - 1; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
    dqueue<int> q;
    q.push_front(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(7);
    q.push_back(5);
    q.push_front(7);
    q.push_front(8);
    q.push_front(9);
    q.push_front(10);
    q.push_back(6);
    q.pop_back();
    q.push_back(20);
    cout <<"is empty or not..   "<< q.empty() << "\n";
    q.display();
    cout<<"\n";
    cout<<q.get_back();
     cout<<"\n";
    cout<<q.get_front();
        cout <<"\nis full or not..   "<< q.full() << "\n";

    return 0;
}




/*
output -->


PS F:\Cpp_programes\.vscode\cppTasks\day_20> cd "f:\Cpp_programes\.vscode\cppTasks\day_20\" ; if ($?) { g++ Dqueueimp.cpp -o Dqueueimp } ; if ($?) { .\Dqueueimp }  
is empty or not..   0
10 9 8 7 2 3 4 7 5 20 
20
10
is full or not..   1


*/

