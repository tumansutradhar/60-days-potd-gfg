class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {
        unordered_set<int> squares;
        for (int x : arr)
            squares.insert(x * x);

        int n = arr.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int sum = arr[i] * arr[i] + arr[j] * arr[j];
                if (squares.find(sum) != squares.end())
                    return true;
            }
        }

        return false;
    }
};
