class Solution
{
public:
    int kBitFlips(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> flip(n + 1, 0);
        int flips = 0, ops = 0;

        for (int i = 0; i < n; i++)
        {
            flips += flip[i];

            int cur = (arr[i] + flips) % 2;

            if (cur == 0)
            {
                if (i + k > n)
                    return -1;
                ops++;
                flips++;
                flip[i + k]--;
            }
        }
        return ops;
    }
};
