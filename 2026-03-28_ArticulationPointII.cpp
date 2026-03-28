class Solution
{
public:
    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> disc(V, -1), low(V), parent(V, -1);
        vector<bool> isAP(V, false);
        int timer = 0;

        function<void(int)> dfs = [&](int u)
        {
            disc[u] = low[u] = timer++;
            int children = 0;

            for (int v : adj[u])
            {
                if (disc[v] == -1)
                {
                    children++;
                    parent[v] = u;
                    dfs(v);
                    low[u] = min(low[u], low[v]);

                    if (parent[u] == -1 && children > 1)
                        isAP[u] = true;
                    if (parent[u] != -1 && low[v] >= disc[u])
                        isAP[u] = true;
                }
                else if (v != parent[u])
                { // back edge
                    low[u] = min(low[u], disc[v]);
                }
            }

            if (parent[u] == -1 && children > 1)
                isAP[u] = true;
        };

        for (int i = 0; i < V; i++)
            if (disc[i] == -1)
                dfs(i);

        vector<int> result;
        for (int i = 0; i < V; i++)
            if (isAP[i])
                result.push_back(i);

        return result.empty() ? vector<int>{-1} : result;
    }
};
