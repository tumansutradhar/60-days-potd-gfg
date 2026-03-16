class Solution
{
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2)
    {
        int n = a1.size();
        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefSum = 0, maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            prefSum += (a1[i] - a2[i]);

            if (mp.count(prefSum))
            {
                maxLen = max(maxLen, i - mp[prefSum]);
            }
            else
            {
                mp[prefSum] = i;
            }
        }
        return maxLen;
    }
};
