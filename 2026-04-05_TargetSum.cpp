class Solution
{
public:
    int totalWays(vector<int> &arr, int target)
    {
        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int num : arr)
        {
            unordered_map<int, int> next;
            for (auto &[sum, cnt] : dp)
            {
                next[sum + num] += cnt;
                next[sum - num] += cnt;
            }
            dp = next;
        }
        return dp.count(target) ? dp[target] : 0;
    }
};