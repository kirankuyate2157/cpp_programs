#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <class T>
class linkedlist
{
    Node<T> *head;
    int length;

public:
    linkedlist()
    {
        head = NULL;
        length = 0;
    }

    void insertAtHead(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            ptr->next = head;
            head = ptr;
        }
        length += 1;
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int size()
    {
        return length;
    }
    void insertAtend(T data)
    {
        Node<int> *ptr = new Node<T>(data);
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            Node<T> *temp = head;
            while (temp != NULL)
            {
                temp = temp->next;
            }
            temp = ptr;
        }
        length++;
    }
    T delethead()
    {
        T deletedNode = NULL;
        Node<T> *temp = head;
        if (head == NULL)
        {
            cout << "nothing to delete any node..\n";
            return NULL;
        }
        else if (temp->next == NULL)
        {
            deletedNode = head->data;
            delete (head);
            head = NULL;
        }
        else
        {
            head = temp->next;
            deletedNode = temp->data;
            delete (temp);
        }
        length--;
        return deletedNode;
    }

    T deletEnd()
    {
        T deletedNode = NULL;
        Node<T> *temp = head;
        if (head == NULL)
        {
            cout << "\nnothing to delete any node..";
            return NULL;
        }
        else if (temp->next == NULL)
        {
            deletedNode = head->data;
            delete (head);
            head = NULL;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            deletedNode = temp->next->data;
            delete (temp->next);
            temp->next = NULL;
        }
        length--;
        return deletedNode;
    }
    void insertAtMid(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == NULL)
        {
            head = ptr;
        }
        else if (head->next == NULL)
        {
            head->next = ptr;
        }
        else
        {
            int i = 1;
            Node<T> *temp = head;
            while (i != length / 2)
            {
                temp = temp->next;
                i++;
            }
            Node<T>*temp2 = temp->next;
            temp->next= ptr;
            temp->next = temp2;
        }
        length++;
    }
};

int main()
{
    linkedlist<int> ll;
    ll.insertAtend(100);
    ll.insertAtend(110);
    ll.insertAtend(120);
    ll.insertAtend(130);
    ll.display();
    cout << ll.size() << " ";
    ll.delethead();
    cout << ll.size() << " ";
    ll.delethead();
    ll.insertAtMid(10);
    cout << ll.size() << " ";
    ll.display();
    ll.insertAtMid(20);
    ll.insertAtMid(30);
    ll.insertAtMid(40);
    ll.display();
    return 0;
}
