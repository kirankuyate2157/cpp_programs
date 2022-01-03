#include <bits/stdc++.h>
using namespace std;
// A linked list node
struct Node{
    int data;
    struct Node *next;
};
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout <<temp->data;
        temp = temp->next;
    }
}

int main()
{
    Node *head;
    Node *second;
    Node *third;
    //data allocation
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;
    display(head);
    return 0;
}