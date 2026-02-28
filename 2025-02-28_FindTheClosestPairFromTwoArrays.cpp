class Solution
{
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x)
    {
        int n = arr1.size();
        int m = arr2.size();

        vector<int> ans;
        int i = 0;
        int j = m - 1;
        int diff = INT_MAX;

        while (i < n && j >= 0)
        {
            int currDiff = abs(x - (arr1[i] + arr2[j]));

            if (currDiff < diff)
            {
                diff = currDiff;
                ans.clear();
                ans.push_back(arr1[i]);
                ans.push_back(arr2[j]);
            }

            if (arr1[i] + arr2[j] < x)
            {
                i++;
            }
            else if (arr1[i] + arr2[j] == x)
            {
                break;
            }
            else
            {
                j--;
            }
        }

        return ans;
    }
};
