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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2, s3;
        while (l1 != NULL)
        {
            int x = l1->val;
            s1.push(x);
            // cout << x << ",";
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            int x = l2->val;
            s2.push(x);
            // cout << x << ",";
            l2 = l2->next;
        }
        int carry = 0;
        while (!s1.empty() && !s2.empty())
        {
            int a = s1.top();
            int b = s2.top();
            s1.pop();
            s2.pop();
            int x = a + b;
            x += carry;
            carry = 0;
            carry = x / 10;
            s3.push(x % 10);
        }
        while (!s1.empty())
        {
            int a = s1.top();
            s1.pop();
            a += carry;
            carry = 0;
            carry = a / 10;
            s3.push(a % 10);
        }
        while (!s2.empty())
        {
            int a = s2.top();
            s2.pop();
            a += carry;
            carry = 0;
            carry = a / 10;
            s3.push(a % 10);
        }
        if (carry > 0)
        {
            s3.push(carry);
        }

        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (!s3.empty())
        {
            int a = s3.top();
            s3.pop();
            ListNode *temp = new ListNode(a);
            cur->next = temp;
            cur = cur->next;
        }

        return head->next;
    }

    ListNode *makeList(vector<int> arr)
    {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;

        for (int i = 0; i < arr.size(); i++)
        {
            ListNode *temp = new ListNode(arr[i]);
            cur->next = temp;
            cur = cur->next;
        }
        return head->next;
    }
    void print(ListNode *head)
    {
        cout << " list : ";
        while (head != NULL)
        {
            cout << head->val << ",";
            head = head->next;
        }
    }
};
int main()
{
    Solution obj;
    vector<int> arr1 = {7, 2, 4, 3};
    vector<int> arr2 = {5, 6, 4};
    ListNode *l1 = obj.makeList(arr1);
    ListNode *l2 = obj.makeList(arr2);
    cout << "addition of give numeberse is  : ";
    ListNode *ans = obj.addTwoNumbers(l1, l2);
    obj.print(ans);

    return 0;
}