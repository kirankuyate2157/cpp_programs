#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void insert();
void display(struct node *head);
void reverseList(struct node *head)
{
    struct node *prev = NULL;
    struct node *cur = head;
    struct node *cur_next = head->next;

    while (cur != NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = cur_next;
        cur = cur_next;
        if (cur_next == NULL)
        {
            break;
        }
        cur_next = cur->next;
    }
    ;
};
int main() 
{

return 0;
}