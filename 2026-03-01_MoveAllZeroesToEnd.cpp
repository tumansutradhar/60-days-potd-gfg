class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {
        int pos = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != 0)
                arr[pos++] = arr[i];
        }
        while (pos < arr.size())
            arr[pos++] = 0;
    }
};
