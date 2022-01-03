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
        if (full())
        {
            cout << " \n *----- order is full..! -----*\n \tplease wait for a minutes until an unless previous orderes was not serve ....";
            return;
        }
        else if ((rear + 1) % N == front)
        {
            return;
        }
        else if (isempty())
        {
            front = rear = 0;
            cout << "\t Order is placed..!!!!\n";
        }
        else
        {
            rear = (rear + 1) % N;
            cout << "\t Order is placed..!!!!\n";
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

    void servorder()
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
                front++;
                length--;
            }
        }
        else
        {
            for (int i = front; i <= N - 1; i++)
            {
                cout << arr[i] << " ";
                front++;
                length--;
            }
            if ((front == N) && (rear < front))
            {
                front = ((front) % N);
            }
            // cout << "front=  " << front;
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
                if (front == rear)
                {
                    front = rear = -1;
                    // break;
                }
                else
                {
                    front++;
                }
                length--;
            }
  }
          cout << "\n*------  your order has been server please enjoy it  -------*\n ";
    }

    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\n \t*----order is empty -----*\n";
        }
        else if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            // cout << "front  ->" << front << "  rear --> " << rear;
        }
        else
        {
            // cout << "front  ->" << front << "  rear --> " << rear;
            for (int i = front; i <= N - 1; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout<<"\n";
    }

    bool full()
    {
        if ((front == 0 && rear == N - 1) || (front == rear + 1)) //when  front at first position & rear at the end it means queue is full or in circuler array front crosses the rear means queue is full...
            return true;
        else
            return false;
    }

    int size()
    {
        return length;
    }

    T frontq()
    {
        return arr[front];
    }
    T end()
    {
        return arr[rear];
    }
};

int main()
{

    queue<int> piza;
    bool flag = true;
    cout << "*------  welcome to Kran`s Pizza shope  ------*\n";
    while (flag)
    {
        cout << "\nselect any one...\n";
        cout << "\t1.order now\n\t2.check ordere order \n\t3.server all orders\n\t4.exit\n";
        int op;
        cout << "....  ";
        cin >> op;
        switch (op)
        {
        case 1:
            int q;
            cout << "enter quantity .. ";
            cin >> q;
            piza.push(q);
            break;
        case 2:
            int q2;
            cout << "\n\t1.check first order\n\t2.check last order\n\t3.check current ordered orders\n\t4.check order limits\n\t5.exit \n";
            cout << " ...  ";
            cin >> q2;
            if (q2 == 1)
            {
                cout << piza.frontq() << "\n";
                break;
            }
            else if (q2 == 2)
            {
                cout << piza.end() << "\n";
                break;
            }
            else if (q2 == 3)
            {
                cout << "\n\tOrdered ordere is  " << piza.size();
                cout << "\n\t\tordere all orders details :  \n\t";
                piza.display();
                break;
            }
            else if (q2 == 4)
            {
                cout << "\n\t order limit is 10 \n\tCurrent ordred ordere is " << piza.size();
                break;
            }
            else if(q2==5){
                cout<<"\n\t Thank you !! \n\t\t see you again..";
                flag=false;
                break;
            }
            else
            {cout<<"enter valid input";
                break;
            }
        case 3:
    // if(piza.full()){
            piza.servorder();
            // }
    // else{
    //     cout<<" please wait for minutes ..when order is full then servyou orders also..";
    // }
            break;
        case 4:
       cout<<"\n\t Thank you !! \n\t\t see you again..";
            flag = false;
            break;
        default:
            cout << "\tenter valid input...!";
            break;
        }
    }
    return 0;
}

/*

Output --->

PS F:\Cpp_programes> cd "f:\Cpp_programes\.vscode\cppTasks\day_20\" ; if ($?) { g++ pizzaordrQueue.cpp -o pizzaordrQueue } ; if ($?) { .\pizzaordrQueue }
*------  welcome to Kran`s Pizza shope  ------*

select any one...
        1.order now
        2.check ordere order 
        3.server all orders
        4.exit
....  1
enter quantity .. 23
         Order is placed..!!!!

select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  1
enter quantity .. 34
         Order is placed..!!!!

select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  1  
enter quantity .. 12 
         Order is placed..!!!!

select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  2

        1.check first order
        2.check last order
        3.check current ordered orders
        4.check order limits
        5.exit
 ...  3

        Ordered ordere is  3
                ordere all orders details :
        23 34 12

select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  3
23 34 12 
*------  your order has been server please enjoy it  -------*

select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  4

         Thank you !!
                 see you again..





PS F:\Cpp_programes\.vscode\cppTasks\day_20> cd "f:\Cpp_programes\.vscode\cppTasks\day_20\" ; if ($?) { g++ pizzaordrQueue.cpp -o pizzaordrQueue } ; if ($?) { .\pizzaordrQueue }
*------  welcome to Kran`s Pizza shope  ------*
select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  1
enter quantity .. 20
         Order is placed..!!!!
select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  1
enter quantity .. 22
         Order is placed..!!!!
select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  1
enter quantity .. 12
         Order is placed..!!!!
select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  1
enter quantity .. 10
         Order is placed..!!!!
select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  1
enter quantity .. 2
         Order is placed..!!!!
select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  3
 please wait for minutes ..when order is full then servyou orders also..select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  2

        1.check first order
        2.check last order
        3.check current ordered orders
        4.check order limits
        5.exit
 ...  3

        Ordered ordere is  5
                ordere all orders details :
        20 22 12 10 2
select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  2

        1.check first order
        2.check last order
        3.check current ordered orders
        4.check order limits
        5.exit
 ...  1
20
select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  2

        1.check first order
        2.check last order
        3.check current ordered orders
        4.check order limits
        5.exit
 ...  2
2
select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  3
 please wait for minutes ..when order is full then servyou orders also..select any one...
        1.order now
        2.check ordere order
        3.server all orders
        4.exit
....  4
         Thank you !!
                 see you agai



*/
