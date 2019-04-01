#include "common.hh"
#include "bt.hh"

void get_all_paths_recur(TreeNode *curr, vector<int>& curr_path, vector< vector<int> >& out) {
  if (curr == NULL) {
    return;
  }

  curr_path.push_back(curr->val);
  if (curr->left == NULL && curr->right == NULL) {
    // leaf node
    out.push_back(curr_path);
    curr_path.pop_back();
    return;
  }

  get_all_paths_recur(curr->left, curr_path, out);

  get_all_paths_recur(curr->right, curr_path, out);

  curr_path.pop_back();
}

vector< vector<int> > get_all_paths(TreeNode* root) {
  vector< vector<int> > out;
  vector<int> curr_path;
  get_all_paths_recur(root, curr_path, out);
  return out;
}

int main() {
  TreeNode *root = new TreeNode(10,
      new TreeNode(5, new TreeNode(1, new TreeNode(-5, NULL, NULL), NULL), NULL),
      new TreeNode(15, NULL, NULL));

  auto out = get_all_paths(root);
  for (auto v : out) {
    for (auto val : v) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}

