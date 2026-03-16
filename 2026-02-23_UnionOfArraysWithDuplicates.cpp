class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        unordered_set<int> st;
        vector<int> result;

        for (int x : a)
            st.insert(x);
        for (int x : b)
            st.insert(x);

        for (int x : st)
            result.push_back(x);

        return result;
    }
};
