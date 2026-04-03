class Solution
{
public:
    vector<int> diagView(vector<vector<int>> mat)
    {
        int n = mat.size();
        vector<int> result;

        for (int d = 0; d < 2 * n - 1; d++)
        {
            int r = (d < n) ? 0 : d - n + 1;
            int c = (d < n) ? d : n - 1;
            while (r < n && c >= 0)
            {
                result.push_back(mat[r][c]);
                r++;
                c--;
            }
        }
        return result;
    }
};
