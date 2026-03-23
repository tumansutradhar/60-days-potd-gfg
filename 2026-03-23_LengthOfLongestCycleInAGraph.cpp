class Solution
{
public:
    int longestCycle(int V, vector<vector<int>> &edges)
    {
        vector<int> next(V, -1);
        for (auto &e : edges)
            next[e[0]] = e[1];

        vector<int> visited(V, 0);
        int ans = -1, timer = 1;

        for (int i = 0; i < V; i++)
        {
            if (visited[i])
                continue;

            int cur = i, start = timer;

            while (cur != -1 && visited[cur] == 0)
            {
                visited[cur] = timer++;
                cur = next[cur];
            }

            if (cur != -1 && visited[cur] >= start)
            {
                ans = max(ans, timer - visited[cur]);
            }
        }
        return ans;
    }
};
