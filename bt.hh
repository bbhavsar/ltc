// Helper header file for binary tree problems

struct Node {
    int val;
    Node *left, *right;
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
};

Node *addElem(Node * root, int elem) {
    Node *n = new Node;
    n->val = elem;
    n->left = n->right = NULL;
    if (root == NULL) {
        return n;
    }

    Node *parent = NULL;
    Node *curr = root;
    while (curr != NULL) {
        parent = curr;
        if (elem <= curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    assert(parent != NULL);
    if (elem <= parent->val) {
        parent->left = n;
    } else {
        parent->right = n;
    }

    return root;
}

void inorder(Node *curr, vector<int> *out) {
    if (curr == NULL) {
        return;
    }
    inorder(curr->left, out);
    out->push_back(curr->val);
    inorder(curr->right, out);
}

vector< vector<int> > levelOrder(Node *root) {
    vector< vector<int> > result;
    if (root == NULL) {
        return result;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int num_nodes = q.size();
        result.push_back(vector<int>());
        const int level = result.size() - 1;
        while (num_nodes > 0) {
            assert(!q.empty());
            Node *curr = q.front();
            assert(curr != NULL);
            q.pop();
            result[level].push_back(curr->val);
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
            num_nodes--;
        }
    }

    return result;
}

