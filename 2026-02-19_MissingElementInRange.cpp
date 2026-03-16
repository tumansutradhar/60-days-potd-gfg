class Solution
{
public:
    vector<int> missinRange(vector<int> &arr, int low, int high)
    {
        vector<int> ans;

        if (low > high)
            return ans;

        vector<bool> present(high - low + 1, false);

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= low && arr[i] <= high)
            {
                present[arr[i] - low] = true;
            }
        }

        for (int i = 0; i <= high - low; i++)
        {
            if (!present[i])
            {
                ans.push_back(low + i);
            }
        }

        return ans;
    }
};
