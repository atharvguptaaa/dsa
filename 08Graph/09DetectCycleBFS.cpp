#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfsCycle(int start, vector<int> &vis, vector<int> adj[])
    {
        queue<pair<int, int>> q;
        q.push({start, -1});
        vis[start] = 1;

        while (!q.empty())
        {
            int vertex = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[vertex])
            {
                if (!vis[it])
                {
                    q.push({it, vertex});
                    vis[it] = 1;
                }
                else if (it != parent)  // If the adjacent node is visited and not the parent, there is a cycle
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (bfsCycle(i, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1); // This creates a cycle: 1-2-3-4-1
    adj[1].push_back(4);

    Solution obj;
    bool result = obj.isCycle(V, adj);

    if (result)
    {
        cout << "Cycle detected!\n";
    }
    else
    {
        cout << "No cycle detected.\n";
    }

    return 0;
}

//tc: tc of bfs - O(N + 2E)
//sc: queue +vis array -> O(N)