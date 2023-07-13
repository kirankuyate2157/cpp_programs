#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        map<int, vector<int>> graph; // graph of  src: required to must visit
        map<int, int> mt;            // counting preReired nodes  so for taking care of size req graph so bfs next movments
        for (auto x : prerequisites)
        {
            graph[x[1]].push_back(x[0]);
            mt[x[0]]++;
        }
        queue<int> q;    // bfs
        vector<int> ans; // cnting  the node first note in graph means visited(learned courses) then later tracking graph nodes
        for (int i = 0; i < numCourses; i++)
        {
            if (!mt.count(i))
            {
                q.push(i);
                ans.push_back(i);
            }
        }

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto ele : graph[x])
            {
                mt[ele]--; // if cnt of preq cources is over then we can add ans i.e counting it and further exploring whther it preqisites is there or not satifying means cycle is created then we can`t add them
                if (mt[ele] == 0)
                {
                    ans.push_back(ele);
                    q.push(ele);
                }
            }
        }
        return ans.size() == numCourses ? true : false;
    }
};

int main()
{
    int n = 2;
    vector<vector<int>> courses = {{1, 0}, {0, 1}};
    Solution obj;
    cout << " can finish all courses : ";
    obj.canFinish(n, courses) ? cout << " yes" : cout << " no";

    return 0;
}