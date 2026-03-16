class Solution
{
public:
    vector<string> generateIp(string &s)
    {
        vector<string> result;
        backtrack(s, 0, 0, "", result);
        return result;
    }

private:
    void backtrack(string &s, int idx, int parts, string curr, vector<string> &result)
    {
        if (parts == 4 && idx == s.size())
        {
            curr.pop_back();
            result.push_back(curr);
            return;
        }
        if (parts == 4 || idx == s.size())
            return;

        for (int len = 1; len <= 3; len++)
        {
            if (idx + len > s.size())
                break;

            string seg = s.substr(idx, len);

            if (seg.size() > 1 && seg[0] == '0')
                break;
            if (stoi(seg) > 255)
                break;

            backtrack(s, idx + len, parts + 1, curr + seg + ".", result);
        }
    }
};
