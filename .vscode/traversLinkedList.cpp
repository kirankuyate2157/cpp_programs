#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
//list taversing

void linked_list(struct node *ptr)
{
    while (ptr != NULL)
    {

        cout<<"element: "<< ptr->data<<" ,";
        ptr = ptr->next;
    }
}



int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    first->data = 20;
    second->data = 30;
    third->data = 40;

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;
    linked_list(head);
  
    return 0;
}