#include <bits/stdc++.h>
using namespace std;
/*
    The function DFS performs a depth-first search starting from a node s in the graph.
    The visited vector keeps track of nodes that have been visited during the DFS traversal.
    The dfsVisited vector keeps track of nodes that are visited in the current DFS path.
    The checkCycle vector is used to mark nodes that are part of a cycle.
    Initially, all nodes are marked as not visited (visited and dfsVisited vectors are false).
    For each node in the graph, if it has not been visited, the DFS function is called.
    During the DFS traversal, if an adjacent node is not visited, the DFS function is recursively called for that node.
    If the recursive call returns true, it means that a cycle is detected, and the current node s is marked as part of a cycle in the checkCycle vector.
    If an adjacent node is already visited and also part of the current DFS path (dfsVisited is true), it indicates a cycle, and the current node s is marked as part of a cycle in the checkCycle vector.
    After exploring all adjacent nodes, the current node s is marked as not visited in the current DFS path (dfsVisited[s] = false).
    Finally, the eventualSafeNodes function iterates over all nodes and adds the nodes that are not part of any cycle (marked as false in the checkCycle vector) to the ans vector.
    The ans vector is returned as the eventual safe nodes in the graph.

The main idea is to perform a DFS traversal and detect cycles in the graph. Nodes that are not part of any cycle are considered eventual safe nodes. The dfsVisited vector is used to keep track of the current path and detect cycles. The checkCycle vector is used to mark nodes that are part of a cycle.*/
class Solution
{
public:
    bool DFS(int s, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsVisited, vector<bool> &checkCycle)
    {
        visited[s] = dfsVisited[s] = true; // Mark the current node as visited and in the current DFS path
        for (auto it : graph[s])
        {
            if (!visited[it])
            { // If the adjacent node is not visited
                if (DFS(it, graph, visited, dfsVisited, checkCycle))
                    return checkCycle[s] = true; // If a cycle is detected, mark the current node as part of a cycle
            }
            else if (dfsVisited[it])
            {                                // If the adjacent node is visited and in the current DFS path
                return checkCycle[s] = true; // A cycle is detected, mark the current node as part of a cycle
            }
        }
        dfsVisited[s] = false; // Mark the current node as not visited in the current DFS path
        return false;          // No cycle detected, current node is safe
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<bool> visited(v), dfsVisited(v), checkCycle(v);
        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                DFS(i, graph, visited, dfsVisited, checkCycle);
        }
        for (int i = 0; i < v; i++)
        {
            if (!checkCycle[i])
                ans.push_back(i); // Add the nodes that are not part of any cycle (eventual safe nodes) to the result
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    Solution obj;
    cout << " safe node state are : ";
    vector<int> ans = obj.eventualSafeNodes(graph);
    cout << ans.size() << endl;

    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }
    cout << " ]";
    return 0;
}