#include "common.hh"

vector<int> convertStrToInt(const vector<string>& strVec) {
    vector<int> result;

    for (const string& s  : strVec) {
        if (s.find('#') == string::npos) {
            cout << s << " ";
            result.emplace_back(stoi(s));
        }
    }
    return result;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
};

class Codec {
private:

    void serialize(TreeNode *curr, string& str) {
        if (curr == NULL) {
            str += "#,";
            return;
        }
        str += to_string(curr->val) + ",";
        serialize(curr->left, str);
        serialize(curr->right, str);
    }

    TreeNode *deserialize(vector<string>::iterator &it, vector<string>::const_iterator end) {
        if (it == end || it->find('#') != string::npos) {
            return NULL;
        }

        TreeNode *n = new TreeNode(stoi(*it));
        if (++it != end) {
            n->left = deserialize(it, end);
        } else {
            return n;
        }
        if (++it != end) {
            n->right = deserialize(it, end);
        } else {
            return n;
        }
        return n;
    }

public:
    vector<string> splitString(const string& str, char delimiter) {
        stringstream ss(str);
        string token;
        vector<string> result;
        while (getline(ss, token, delimiter)) {
            result.emplace_back(token);
        }

        return result;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serialize(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens = splitString(data, ',');
        vector<string>::iterator it = tokens.begin();
        return deserialize(it, tokens.end());
    }
};

void inorder(TreeNode *curr) {
    if (curr == NULL) {
        return;
    }
    inorder(curr->left);
    cout << curr->val << " ";
    inorder(curr->right);
}

int main() {
    Codec c;
    string str = "1,2,3, 4, 5, -10, #,";
    for (string elem :  c.splitString(str, ',')) {
        cout << elem << " ";
    }
    cout << endl;

    TreeNode *root = new TreeNode(10, new TreeNode(5, new TreeNode(2), new TreeNode(8)), new TreeNode(15));
    string s = c.serialize(root);
    cout << "serialized tree " << s << endl;
    TreeNode *decodedTree = c.deserialize(c.serialize(root));
    inorder(decodedTree);
    cout << endl;

    return 0;
}

