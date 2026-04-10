class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        int n = arr.size();
        int first = INT_MAX, second = INT_MAX;
        int savedFirst = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= first)
            {
                first = arr[i];
            }
            else if (arr[i] <= second)
            {
                second = arr[i];
                savedFirst = first;
            }
            else
            {
                return {savedFirst, second, arr[i]};
            }
        }
        return {};
    }
};
