#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
class mystack
{
    struct node *head;
    int size, top;
    struct node *middle;

public:
    mystack()
    {
        head = NULL;
        middle = NULL;
        size = 0;
    }


    void display()
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }



    void push(int x)
    {
        if (head == NULL)
        {
            head->prev = NULL;
            head->data = x;
            head->next = NULL;
            middle = head;
            size++;
        }

        else
        {
            struct
                node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            if (size % 2 == 1)
                middle = middle->next;
            node *ls = temp;
            temp->next->data = x;
            temp = temp->next;
            temp->prev = ls;
            size++;
        }
    }



    int pop()
    {
        int poped;
        if (head == NULL)
            return -1;
        else if (head->next == NULL)
        {
            poped = head->data;
            head = NULL;
            middle = NULL;
            size--;
        }
        else
        {
            struct node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            if (size % 2 == 0)
                middle = middle->prev;
            poped = temp->data;
            temp = NULL;
            size--;
        }
        return poped;
    }



    int middleEle()
    {
        return middle->data;
    }

    int popmiddle()
    {
        struct node *poped;
        int del;
        if (middle = NULL)
            return -1;
        else if (middle->next == NULL)
        {
            poped = middle;
            head = NULL;
            middle = NULL;
            size--;
        }
        else
        {
            if (size % 2 == 0)
            {
                poped = middle;
                middle = middle->prev;
                middle->next = middle->next->next;
                del = poped->data;
                free(poped);
            }
            else
            {
                poped = middle;
                middle = middle->next;
                middle->prev = poped->prev;
                del = poped->data;
                free(poped);
            }
        }
        return del;
    }


    
};

int main()
{
    mystack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.pop();
    st.display();
    cout << st.middleEle();

    return 0;
}