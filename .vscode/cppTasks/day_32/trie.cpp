#include <bits/stdc++.h>
using namespace std;
class trieNode
{
public:
    trieNode *child[26];
    bool eof = false;
    trieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
class trie
{
    trieNode *root;
    int words = 0;

public:
    void insert(string s)
    {

        trieNode *temp = root;
        for (int i = 0; i < s.length(); i++)
        {
            int x = s[i] - 'a';
            cout << x << s[i] << " ";
            if (!temp->child[x])
            {
                temp->child[x] = new trieNode;
            }
            temp = temp->child[x];
        }
        words++;
        temp->eof = true;
    }

    bool search(string s)
    {
        trieNode *temp = root;
        for (int i = 0; i < s.length(); i++)
        {
            int x = s[i] - 'a';
            if (!temp->child[x])
                return false;
            temp = temp->child[x];
        }
        return true;
    }
};
int main()
{
    string a = "hello";
    trie r;
    r.insert(a);
    cout << "\nlets find\n";
    return 0;
}