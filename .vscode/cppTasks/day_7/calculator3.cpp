#include <iostream>
using namespace std;

int calculator()
{
    bool act = true;
    while (act)
    {
     cout << "\tWelcome to the kiran calculator"; 
    cout << "\tenter...";
    cout << "\n\t1. additiion\n\t2.substraction\n\t3.multiplication\n\t4.division\n\t5.reminder\n\t6.exit\n\t";        //selecting  opration

        int a, b; 
        char op;
        cin >> op;                //taking opration inpute
        if (op == '6')       // program Exit condition 
        {
            act = false;
            cout << "thank you have great day !!";
            break;
        }
        cin >> a;   //first oprand

        cin >> b;   //second  oprand 

        float res;
        switch (op)
        {
        case '1':
            res = a + b;
            cout << "ans. " << res<<"\n";
            break;
        case '2':
            res = a - b;
            cout << res<<"\n";
            break;
        case '3':
            res = a * b;

            cout << "ans. " << res<<"\n";
            break;
        case '4':
            res = a / b;
            cout << "ans. " << res<<"\n";
            break;
        case '5':
            res = a % b;
            cout << "ans. " << res<<"\n";
            break;

        default:
            cout << "invalid input";
            break;
        }

        
    }
}






int main()
{
 
    calculator();

    return 0;
}