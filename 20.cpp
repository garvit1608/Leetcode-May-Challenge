/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  int kthSmallest(TreeNode *root, int k)
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!root)
      return -1;

    int left = kthSmallest(root->left, k);

    if (left != -1)
      return left;

    v.push_back(root->val);

    if (v.size() == k)
      return v[k - 1];

    int right = kthSmallest(root->right, k);

    if (right != -1)
      return right;

    return -1;
  }

private:
  vector<int> v;
}