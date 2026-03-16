class Solution
{
public:
    int countSquare(vector<vector<int>> &mat, int x)
    {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pre[i][j] = mat[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

        int count = 0;
        int maxSide = min(n, m);

        for (int sz = 1; sz <= maxSide; sz++)
        {
            for (int i = sz; i <= n; i++)
            {
                for (int j = sz; j <= m; j++)
                {
                    int sum = pre[i][j] - pre[i - sz][j] - pre[i][j - sz] + pre[i - sz][j - sz];
                    if (sum == x)
                        count++;
                }
            }
        }
        return count;
    }
};
