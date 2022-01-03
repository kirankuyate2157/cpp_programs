#include <iostream>
using namespace std;

template <class T>
class queue
{
    int N = 10;
    T arr[10];
    int length = 0;
    int front, rear;

public:
    queue()
    {
        front = rear = -1;
    }

    bool isempty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(T x)
    {
        if ((rear + 1) % N == front)
        {
            return;
        }
        else if (isempty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % N;
        }
        length++;
        arr[rear] = x;
    }

    T pop()
    {
        T poped;
        if (isempty())
        {
            return -1;
        }
        else if (front == rear)
        {
            T poped = arr[front];
            front = rear = -1;
            length--;
            return poped;
        }
        else
        {
            poped = arr[front];
            front = (front + 1) % N;
            length--;
            return poped;
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
            for (int i = front; i <= N-1; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }



    int size()
    {
        return length;
    }

    T frontq()
    {
        return arr[front];
    }
};

int main()
{

    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    // q.pop();
    q.push(12);
    q.push(13);

    q.pop();
     q.push(15);
    // cout << q.isempty();
    // cout << "\n"
    //  << q.frontq();
    cout << "\nsize of the queue is -->  " << q.size();
    cout << "\n";
    q.display();
    return 0;
}

/*


Output --->

PS F:\Cpp_programes\.vscode\cppTasks\day_20> cd "f:\Cpp_programes\.vscode\cppTasks\day_20\" ; if ($?) { g++ queueImp.cpp -o queueImp } ; if ($?) { .\queueImp }



size of the queue is -->  10
4 5 6 7 8 9 10 12 13 15 

*/




