class Solution
{
public:
    int countSubarrays(vector<int> &arr)
    {
        int n = arr.size(), count = 0;
        stack<int> st;
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++)
            count += (nse[i] - i);

        return count;
    }
};
