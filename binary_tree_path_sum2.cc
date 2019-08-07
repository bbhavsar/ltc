#include "common.hh"
#include "bt.hh"

class Solution {

  void pathSumRecur(TreeNode *curr, int remain, vector<int>& curr_path,
                    vector< vector<int> >& result) {
    if (curr == NULL) {
      return;
    }

    if (curr->left == NULL && curr->right == NULL) {
      if (remain == curr->val) {
        curr_path.push_back(curr->val);
        result.push_back(curr_path);
        curr_path.pop_back();
      }
      return;
    }

    curr_path.push_back(curr->val);
    remain -= curr->val;
    pathSumRecur(curr->left, remain, curr_path, result);
    pathSumRecur(curr->right, remain, curr_path, result);
    curr_path.pop_back();
  }

  public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector< vector<int> > result;
      vector<int> curr_path;

      pathSumRecur(root, sum, curr_path, result);
      return result;
    }
};

int main() {


  return 0;
}

