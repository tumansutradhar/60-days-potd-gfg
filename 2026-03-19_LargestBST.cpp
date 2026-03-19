class Solution
{
public:
    tuple<int, int, int, int, bool> help(Node *root)
    {
        if (root == NULL)
        {
            return make_tuple(0, INT_MAX, INT_MIN, 0, true);
        }

        if (root->left == NULL && root->right == NULL)
        {
            return make_tuple(1, root->data, root->data, 1, true);
        }

        auto left = help(root->left);
        auto right = help(root->right);

        int leftSize = get<0>(left);
        int leftMin = get<1>(left);
        int leftMax = get<2>(left);
        int leftLargestBST = get<3>(left);
        bool leftIsBST = get<4>(left);

        int rightSize = get<0>(right);
        int rightMin = get<1>(right);
        int rightMax = get<2>(right);
        int rightLargestBST = get<3>(right);
        bool rightIsBST = get<4>(right);

        int currentSize = 1 + leftSize + rightSize;

        if (leftIsBST && rightIsBST && root->data > leftMax && root->data < rightMin)
        {
            int minValue = (root->left != NULL) ? leftMin : root->data;
            int maxValue = (root->right != NULL) ? rightMax : root->data;
            return make_tuple(currentSize, minValue, maxValue, currentSize, true);
        }

        return make_tuple(currentSize, INT_MIN, INT_MAX, max(leftLargestBST, rightLargestBST), false);
    }
    int largestBst(Node *root)
    {
        auto result = help(root);
        return get<3>(result);
    }
};
