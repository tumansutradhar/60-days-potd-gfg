class Solution
{
public:
    int minTime(vector<int> &arr, int k)
    {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long result = high;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (isPossible(mid, arr, k))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return result;
    }

private:
    bool isPossible(long long maxTime, vector<int> &arr, int k)
    {
        int painters = 1;
        long long currSum = 0;

        for (int length : arr)
        {
            if (length > maxTime)
                return false;

            if (currSum + length > maxTime)
            {
                painters++;
                currSum = length;
            }
            else
            {
                currSum += length;
            }
        }

        return painters <= k;
    }
};
