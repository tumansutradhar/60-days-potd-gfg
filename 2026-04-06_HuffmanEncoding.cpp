class Solution
{
public:
    struct Node
    {
        int freq, order;
        Node *left, *right;
        Node(int f, int o) : freq(f), order(o), left(nullptr), right(nullptr) {}
    };

    struct Compare
    {
        bool operator()(Node *a, Node *b)
        {
            if (a->freq == b->freq)
                return a->order > b->order;
            return a->freq > b->freq;
        }
    };

    void preorder(Node *root, string code, vector<string> &res)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            res.push_back(code);
            return;
        }
        preorder(root->left, code + "0", res);
        preorder(root->right, code + "1", res);
    }

    vector<string> huffmanCodes(string &s, vector<int> f)
    {
        priority_queue<Node *, vector<Node *>, Compare> pq;

        for (int i = 0; i < (int)s.size(); i++)
            pq.push(new Node(f[i], i));

        if (pq.size() == 1)
            return {"0"};

        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();
            Node *merged = new Node(left->freq + right->freq,
                                    min(left->order, right->order));
            merged->left = left;
            merged->right = right;
            pq.push(merged);
        }

        vector<string> result;
        preorder(pq.top(), "", result);
        return result;
    }
};
