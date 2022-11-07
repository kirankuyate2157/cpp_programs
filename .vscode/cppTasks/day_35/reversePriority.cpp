// C++ program to demonstrate priority queue in reverse order
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialising the priority queue
    priority_queue<string, vector<string>, greater<string>> pq;

    // Inserting values in priority queue
    pq.push("physics");
    pq.push("chemistry");
    pq.push("maths");
    pq.push("socialstudies");
    pq.push("biology");

    cout << "The priority queue in reverse order is : ";

    // Printing all elements in priority queue
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
