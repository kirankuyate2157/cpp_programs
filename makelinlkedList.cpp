#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

 void insertAtTail(struct node* head, int val)
 {
    node *n = new node(val);
    if (head == NULL)



    
    {
        head = n;
        return;
    }
 }    



// void insertAtHead(node* head, nt val)
// {
//     node* n = new node(val);
//     n->next = head;
//     head = n;
// }


// void Display(node* head){
//     node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<"->";
//         temp=temp->next;
//     }
//     cout<<"NULL" <<endl;
// }

int main()
{
    node *head = NULL;

//     insertAtTail(head, 1);
//     insertAtTail(head, 2);
//     insertAtTail(head, 3);
//     insertAtTail(head, 5);
// insertAtTail(head,6);

// Display(head);

    return 0;
}