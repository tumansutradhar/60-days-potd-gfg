class Solution
{
public:
    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> parent;
        Node *targetNode = nullptr;

        queue<Node *> q;
        q.push(root);
        parent[root] = nullptr;

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (node->data == target)
                targetNode = node;

            if (node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_map<Node *, bool> visited;
        queue<Node *> fire;

        fire.push(targetNode);
        visited[targetNode] = true;
        int time = 0;

        while (!fire.empty())
        {
            int sz = fire.size();
            bool spread = false;

            while (sz--)
            {
                Node *node = fire.front();
                fire.pop();

                if (node->left && !visited[node->left])
                {
                    visited[node->left] = true;
                    fire.push(node->left);
                    spread = true;
                }
                if (node->right && !visited[node->right])
                {
                    visited[node->right] = true;
                    fire.push(node->right);
                    spread = true;
                }
                if (parent[node] && !visited[parent[node]])
                {
                    visited[parent[node]] = true;
                    fire.push(parent[node]);
                    spread = true;
                }
            }
            if (spread)
                time++;
        }
        return time;
    }
};
