#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << "\n";
}

void createLList(node *&head, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *cur = head;
    while (cur->next != NULL)
    {

        cur = cur->next;
    }
    cur->next = newNode;
    return;
}
// first approch O(n)
bool isPalindrome1(node *head)
{
    vector<int> arr;
    node *cur = head;
    while (cur)
    {
        arr.push_back(cur->data);
        cur = cur->next;
    }
    for (int i = 0; i < arr.size() / 2; i++)
        if (arr[i] != arr[arr.size() - i - 1])
            return false;
    return true;
}
node *reverse(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *prev = NULL;
    node *nex = NULL;
    while (head != NULL)
    {
        nex = head->next;
        head->next = prev;
        prev = head;
        head = nex;
    }
    return prev;
}
bool isPalindrome2(node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    node *temp = head;
    while (slow != NULL)
    {
        if (temp->data != slow->data)
            return false;
        slow = slow->next;
        temp = temp->next;
    }
    return true;
}

int getsize(node *head)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
node *reversK(node *head, int k)
{
    int length = getsize(head);
    node *d = new node(0);
    d->next = head;
    node *prev = d;
    node *cur;
    node *nex;
    while (length >= k)
    {
        cur = prev->next;
        nex = cur->next;
        for (int i = 0; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = cur->next;
        }
        prev = cur;
        length -= k;
    }
    return d->next;
}
int main()
{
    node *head = NULL;
    createLList(head, 3);
    createLList(head, 2);
    createLList(head, 1);
    createLList(head, 12);
    createLList(head, 3);
    // createLList(head, 1);
    print(head);
    cout << isPalindrome2(head);
    // print(reversK(head, 3));
    return 0;
}