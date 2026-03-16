class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], arr[i]);
        }
        vector<int> suffix(n);
        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(arr[i], suffix[i + 1]);
        }
        int leftmax, rightmax, total = 0;
        for (int i = 0; i < n; i++)
        {
            leftmax = prefix[i];
            rightmax = suffix[i];
            if (arr[i] < prefix[i] && arr[i] < suffix[i])
            {
                total += min(leftmax, rightmax) - arr[i];
            }
        }
        return total;
    }
};
