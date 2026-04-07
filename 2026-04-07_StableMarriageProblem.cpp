class Solution
{
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women)
    {
        int n = men.size();
        vector<int> womanPartner(n, -1);
        vector<int> manPartner(n, -1);
        vector<int> nextProposal(n, 0);

        vector<vector<int>> womanRank(n, vector<int>(n));
        for (int w = 0; w < n; w++)
            for (int r = 0; r < n; r++)
                womanRank[w][women[w][r]] = r;

        queue<int> freeMen;
        for (int i = 0; i < n; i++)
            freeMen.push(i);

        while (!freeMen.empty())
        {
            int m = freeMen.front();
            freeMen.pop();
            int w = men[m][nextProposal[m]++];

            if (womanPartner[w] == -1)
            {
                womanPartner[w] = m;
                manPartner[m] = w;
            }
            else
            {
                int curr = womanPartner[w];
                if (womanRank[w][m] < womanRank[w][curr])
                {
                    womanPartner[w] = m;
                    manPartner[m] = w;
                    manPartner[curr] = -1;
                    freeMen.push(curr);
                }
                else
                {
                    freeMen.push(m);
                }
            }
        }
        return manPartner;
    }
};
