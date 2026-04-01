class Solution
{
public:
    int countStrings(int n)
    {
        int zero = 1, one = 1;

        for (int i = 2; i <= n; i++)
        {
            int newZero = zero + one;
            int newOne = zero;
            zero = newZero;
            one = newOne;
        }
        return zero + one;
    }
};
