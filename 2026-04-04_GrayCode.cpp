class Solution
{
public:
    vector<string> graycode(int n)
    {
        vector<string> result;

        for (int i = 0; i < (1 << n); i++)
        {
            int gray = i ^ (i >> 1);
            string bits = "";
            for (int b = n - 1; b >= 0; b--)
                bits += ((gray >> b) & 1) ? '1' : '0';
            result.push_back(bits);
        }
        return result;
    }
};
