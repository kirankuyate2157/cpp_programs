#include <iostream>
using namespace std;

int main()
{    
    int divisor, dividend, quotient, remainder;

    cout << "Enter dividend : ";
    cin >> dividend;

    cout << "Enter divisor : ";
    cin >> divisor;

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    cout << "Quotient = " << quotient << endl;
    cout << "Remainder = " << remainder;

    return 0;
}
// Output---->

// PS F:\Cpp_programes> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ FindQuisRemd.cpp -o FindQuisRemd } ; if ($?) { .\FindQuisRemd }
// Enter dividend : 34
// Enter divisor : 3
// Quotient = 11
// Remainder = 1