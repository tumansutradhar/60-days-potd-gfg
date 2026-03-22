class Solution
{
public:
    int orangesRot(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 2)
                    q.push({i, j});
                if (mat[i][j] == 1)
                    fresh++;
            }

        if (fresh == 0)
            return 0;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;

        while (!q.empty())
        {
            int sz = q.size();
            bool spread = false;

            while (sz--)
            {
                auto [r, c] = q.front();
                q.pop();

                for (auto &d : dirs)
                {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1)
                    {
                        mat[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        spread = true;
                    }
                }
            }
            if (spread)
                time++;
        }
        return fresh == 0 ? time : -1;
    }
};
