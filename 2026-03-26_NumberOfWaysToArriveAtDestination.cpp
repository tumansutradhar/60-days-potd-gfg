class Solution
{
public:
    int countPaths(int V, vector<vector<int>> &edges)
    {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(V, LLONG_MAX);
        vector<long long> ways(V, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto &[v, w] : adj[u])
            {
                long long newDist = dist[u] + w;

                if (newDist < dist[v])
                {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                }
                else if (newDist == dist[v])
                {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[V - 1];
    }
};
