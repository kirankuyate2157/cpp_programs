#include <bits/stdc++.h>
using namespace std;
class WordDictionary
{
    struct node
    {
        char c;
        int end;
        node *child[26];
    };
    node *getNode(char c)
    {
        node *newNode = new node;
        newNode->c = c;
        newNode->end = 0;
        for (int i = 0; i < 26; ++i)
        {
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    node *root = getNode('/');

    void trieInsert(string s)
    {
        int index;
        int i = 0;
        node *cur = root;
        while (s[i])
        {
            index = s[i] - 'a';
            if (!cur->child[index])
            {
                cur->child[index] = getNode(s[i]);
            }
            cur = cur->child[index];
            ++i;
        }
        cur->end += 1;
    }

    bool trieSearch(string s, node *cur, int pos, int n)
    {
        if (s[pos] == '.')
        {
            bool res = false;
            node *curr = cur;
            for (int i = 0; i < 26; ++i)
            {
                if (pos == n - 1 && cur->child[i])
                {
                    curr = cur->child[i];
                    res |= curr->end > 0 ? true : false;
                }
                else if (cur->child[i] && trieSearch(s, cur->child[i], pos + 1, n))
                    return true;
            }
            return res;
        }
        else if (cur->child[s[pos] - 'a'])
        {
            if (pos == n - 1)
            {
                cur = cur->child[s[pos] - 'a'];
                return cur->end > 0 ? true : false;
            }
            return trieSearch(s, cur->child[s[pos] - 'a'], pos + 1, n);
        }
        return false;
    }

public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        trieInsert(word);
    }

    bool search(string word)
    {
        return trieSearch(word, root, 0, word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main()
{

    vector<string> oprations = {"addWord", "addWord", "addWord", "search", "search", "search", "search"};
    vector<string> words = {"bad", "dad", "mad", "pad", "bad", ".ad", "b.."};

    WordDictionary d;
    for (int i = 0; i < oprations.size(); i++)
    {
        if (oprations[i] == "addWord")
        {
            d.addWord(words[i]);
        }
        else
        {
            cout << d.search(words[i]) << "$ ";
        }
    }
}