class Solution
{
public:
    int minCost(vector<vector<int>> &houses)
    {

        int n = houses.size();
        vector<vector<int>> adjDis(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    adjDis[i][j] = abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
                }
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(n, 0);
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            int wt = node.first;
            int ind = node.second;
            if (vis[ind])
                continue;

            vis[ind] = 1;
            sum += wt;

            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    pq.push({adjDis[ind][i], i});
                }
            }
        }

        return sum;
    }
};
