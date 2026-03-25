class Solution
{
public:
    vector<int> minHeightRoot(int V, vector<vector<int>> &edges)
    {
        vector<int> result;
        if (V == 1)
        {
            result.push_back(0);
            return result;
        }

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (degree[i] == 1)
                q.push(i);

        int remaining = V;
        while (remaining > 2)
        {
            int sz = q.size();
            remaining -= sz;

            while (sz--)
            {
                int leaf = q.front();
                q.pop();
                for (int nb : adj[leaf])
                {
                    degree[nb]--;
                    if (degree[nb] == 1)
                        q.push(nb);
                }
            }
        }

        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};
