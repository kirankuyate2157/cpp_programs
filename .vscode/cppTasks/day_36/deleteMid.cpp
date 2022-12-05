#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head && (!head->next))
            return NULL;

        ListNode *slow = head, *fast = head;
        ListNode *prev = new ListNode();

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout<<prev->val<<" "<<slow->val<<"\n";
        prev->next = slow->next;
        return head;
    }
};
int main()
{
    vector<int> arr = {5, 2, 3, 6, 7, 8, 9};
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for (auto x : arr)
    {
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    Solution obj;
    obj.deleteMiddle(head);
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}