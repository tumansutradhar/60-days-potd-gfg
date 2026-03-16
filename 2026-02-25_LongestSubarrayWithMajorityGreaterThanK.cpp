class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                arr[i] = -1;
            }
            else
                arr[i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            arr[i] += arr[i - 1];
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                ans = max(ans, i + 1);
            }
            else if (mp.find(arr[i] - 1) != mp.end())
            {
                ans = max(ans, i - mp[arr[i] - 1]);
            }
            else
            {
                if (mp.count(arr[i]) == 0)
                {
                    mp[arr[i]] = i;
                }
            }
        }
        return ans;
    }
};
