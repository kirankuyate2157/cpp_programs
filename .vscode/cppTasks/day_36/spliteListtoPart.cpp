

#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int n = 0;
        vector<ListNode *> arr(k);
        ListNode *temp = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }
        int len = int(n / k);
        int extra = n % k;
        temp = head;
        for (int i = 0; i < k; i++)
        {
            ListNode *node = new ListNode(), *ptr = node;
            for (int j = 0; j < len + (i < extra ? 1 : 0); ++j)
            {
                // cout << extra << " ";
                ptr = ptr->next = new ListNode(temp->val);
                if (temp->next)
                    temp = temp->next;
            }
            arr[i] = node->next;
        }

        return arr;
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

    vector<ListNode *> ans = obj.splitListToParts(head, 5);
    for (int i = 0; i < ans.size(); i++)
    {
        ListNode *node = ans[i];
        while (node)
        {
            cout << node->val << "->";
            node = node->next;
        }
        cout << " | ";
    }
    return 0;
}