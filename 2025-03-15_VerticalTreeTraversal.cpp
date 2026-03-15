class Solution
{
public:
    vector<vector<int>> verticalOrder(Node *root)
    {
        if (!root)
            return {};

        map<int, vector<int>> mp;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        int mn = 0, mx = 0;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            Node *node = front.first;
            int val = front.second;

            mn = min(mn, val);
            mx = max(mx, val);

            mp[val].push_back(node->data);

            if (node->left)
                q.push({node->left, val - 1});
            if (node->right)
                q.push({node->right, val + 1});
        }

        vector<vector<int>> res;

        for (int i = mn; i <= mx; i++)
        {
            res.push_back(mp[i]);
        }

        return res;
    }
};
