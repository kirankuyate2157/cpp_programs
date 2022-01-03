//  vscode://vscode.github-authentication/did-authenticate?windowid=1&code=7d931b3ac1461ca66514&state=fd2d6180-b5e5-4f26-a39a-4217709c2514 


#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void insert(struct node*&head, int data)
{

    struct node *ptr = new node(data);
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
        }
        temp = ptr;
    }
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    node *head = new node(11);
    insert(head, 12);
    insert(head, 13);
    insert(head, 14);
    insert(head, 14);
    insert(head, 15);

    print(head);
    return 0;
}