#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    class Node
    {
    public:
        int val;
        int key;
        Node *next;
        Node *prev;

        Node(int key, int val)
        {
            this->val = val;
            this->key = key;
        }
    };
    map<int, Node *> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    void addNode(Node *newNode)
    {
        Node *nxt = head->next;
        head->next = newNode;
        newNode->prev = head;

        newNode->next = nxt;
        nxt->prev = newNode;
    }
    void deleteNode(Node *exitNode)
    {
        Node *nPrev = exitNode->prev;
        Node *nNext = exitNode->next;
        nPrev->next = nNext;
        nNext->prev = nPrev;

        // delete exitNode;
    }

    int catchSize;
    LRUCache(int capacity)
    {
        catchSize = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *x = mp[key];
            int value = x->val;

            mp.erase(key);
            deleteNode(x);
            addNode(x);

            mp[key] = head->next;
            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *x = mp[key];
            mp.erase(key);
            deleteNode(x);
        }
        if (mp.size() == catchSize)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    vector<string> opr = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    vector<vector<int>> data = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};
    LRUCache *obj;

    for (int i = 0; i < data.size(); i++)
    {
        if (opr[i] == "LRUCache")
        {
            obj = new LRUCache(data[i][0]);
            cout << "catch created ..!\n";
        }
        else if (opr[i] == "put")
        {
            obj->put(data[i][0], data[i][1]);
            cout << " val putted ..!\n";
        }
        else if (opr[i] == "get")
        {
            int param_1 = obj->get(data[i][0]);
            cout << "val getted : " << param_1 << endl;
        }
    }
    return 0;
}