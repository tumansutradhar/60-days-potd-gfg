class Solution
{
public:
    int countAllPaths(Node *root, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        return dfs(root, k, 0, mp);
    }

private:
    int dfs(Node *node, int k, int currSum, unordered_map<int, int> &mp)
    {
        if (!node)
            return 0;

        currSum += node->data;

        int count = mp[currSum - k];

        mp[currSum]++;
        count += dfs(node->left, k, currSum, mp);
        count += dfs(node->right, k, currSum, mp);
        mp[currSum]--;

        return count;
    }
};
