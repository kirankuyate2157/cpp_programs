#include <bits/stdc++.h>
using namespace std;
class MyHashSet
{
public:
    vector<int> data;
    MyHashSet()
    {
        data.resize(1e6 + 4, 0);
    }

    void add(int key)
    {

        data[key] = 1;
    }

    void remove(int key)
    {
        data[key] = 0;
    }

    bool contains(int key)
    {
        return data[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
int main()
{
    /* initialize
      Input
  ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
  [[], [1], [2], [1], [3], [2], [2], [2], [2]]
  Output
  [null, null, null, true, false, null, true, null, false]

  Explanation
  MyHashSet myHashSet = new MyHashSet();
  myHashSet.add(1);      // set = [1]
  myHashSet.add(2);      // set = [1, 2]
  myHashSet.contains(1); // return True
  myHashSet.contains(3); // return False, (not found)
  myHashSet.add(2);      // set = [1, 2]
  myHashSet.contains(2); // return True
  myHashSet.remove(2);   // set = [1]
  myHashSet.contains(2); // return False, (already removed)

    */
    return 0;
}