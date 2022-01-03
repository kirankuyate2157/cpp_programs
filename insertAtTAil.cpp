#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void insertAtTAil(Node *&head, int val)
{
    struct Node *temp;
    temp = head;
    struct Node *newnode = new Node(val);
    newnode->next = NULL;
    if (temp == NULL)
    {
        temp = newnode;
       
    }
    while (temp->next != NULL)
    {
       temp=temp->next;
        
    }
     temp->next = newnode;
    
}
void display(Node *head)
{
    struct Node *temp = head;
    cout << "linked list is : ";
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    head->data = 10;
    head->next = NULL;
    insertAtTAil(head, 20);
    display(head);
    insertAtTAil(head,30);
    display(head);

    return 0;
}