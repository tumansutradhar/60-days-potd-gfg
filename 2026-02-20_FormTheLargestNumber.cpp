class Solution
{
public:
    string findLargest(vector<int> &arr)
    {
        vector<string> sArr;
        for (int n : arr)
        {
            sArr.push_back(to_string(n));
        }
        sort(sArr.begin(), sArr.end(), [](const string &s1, const string &s2)
             { return (s1 + s2) > (s2 + s1); });
        if (sArr[0] == "0")
            return "0";
        string result = "";
        for (const string &s : sArr)
        {
            result += s;
        }
        return result;
    }
};
