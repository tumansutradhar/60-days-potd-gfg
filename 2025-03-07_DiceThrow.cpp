class Solution
{
public:
    int noOfWays(int m, int n, int x)
    {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
        return helper(m, n, x, dp);
    }

private:
    int helper(int m, int n, int x, vector<vector<int>> &dp)
    {
        if (n == 0 && x == 0)
            return 1;
        if (n == 0 || x <= 0)
            return 0;
        if (dp[n][x] != -1)
            return dp[n][x];

        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            ans += helper(m, n - 1, x - i, dp);
        }
        return dp[n][x] = ans;
    }
};
