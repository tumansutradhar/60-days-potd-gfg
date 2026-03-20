class Solution
{
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<Node *> result;
        Node *pre = nullptr;
        Node *suc = nullptr;

        if (!root)
            return result;

        while (root != nullptr)
        {
            if (root->data < key)
            {
                pre = root;
                root = root->right;
            }
            else if (root->data > key)
            {
                suc = root;
                root = root->left;
            }
            else
            {
                if (root->left)
                {
                    Node *temp = root->left;
                    while (temp->right)
                        temp = temp->right;
                    pre = temp;
                }
                if (root->right)
                {
                    Node *temp = root->right;
                    while (temp->left)
                        temp = temp->left;
                    suc = temp;
                }
                break;
            }
        }

        result.push_back(pre ? pre : nullptr);
        result.push_back(suc ? suc : nullptr);

        return result;
    }
};
