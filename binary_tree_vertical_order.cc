
#include "common.hh"

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
private:

    void recurse(TreeNode *curr, int x, int y, map<int, map<int, vector<int> > >& result) {
        if (curr == NULL) {
            return;
        }
        result[x][y].push_back(curr->val);
        recurse(curr->left, x-1, y + 1, result);
        recurse(curr->right, x+1, y+ 1, result);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, map<int,  vector<int> > > result;
        recurse(root, 0, 0, result);
        vector< vector<int> > r;
        for (auto p : result) {
            for (auto pvec : p.second) {
                r.emplace_back(pvec.second);
            }
        }
        return r;
    }
};

int main() {


    return 0;
}


