class Solution
{
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j1, int j2, vector<vector<int>> &grid)
    {
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return -1e9;
        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = 0;

        for (int d1 = -1; d1 <= 1; d1++)
        {
            for (int d2 = -1; d2 <= 1; d2++)
            {

                int value = 0;
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += solve(i + 1, j1 + d1, j2 + d2, grid);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int maxChocolate(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0, 0, m - 1, grid);
    }
};
