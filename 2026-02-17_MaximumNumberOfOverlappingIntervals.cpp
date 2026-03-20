class Solution
{
public:
    int overlapInt(vector<vector<int>> &arr)
    {
        int max_val = 0;
        for (auto &interval : arr)
            max_val = max(max_val, interval[1]);

        vector<int> diff(max_val + 2, 0);

        for (auto &interval : arr)
        {
            diff[interval[0]] += 1;
            diff[interval[1] + 1] -= 1;
        }

        int maxOverlap = 0, current = 0;

        for (int i = 0; i <= max_val; i++)
        {
            current += diff[i];
            maxOverlap = max(maxOverlap, current);
        }

        return maxOverlap;
    }
};
