/**
 * In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
 * Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
 * We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
 * Return true if and only if the nodes corresponding to the values x and y are cousins.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
  int xParent, xDepth;
  int yParent, yDepth;

public:
  void preOrder(TreeNode *root, int x, int y, int parent, int depth)
  {
    if (root == NULL || (depth == 0 && (root->val == x || root->val == y)))
    {
      return;
    }
    if (root->val == x)
    {
      xParent = parent;
      xDepth = depth;
      return;
    }
    if (root->val == y)
    {
      yParent = parent;
      yDepth = depth;
      return;
    }
    preOrder(root->left, x, y, root->val, depth + 1);
    preOrder(root->right, x, y, root->val, depth + 1);
  }
  bool isCousins(TreeNode *root, int x, int y)
  {
    preOrder(root, x, y, INT_MIN, 0);
    return (xParent != yParent) && (xDepth == yDepth);
  }
};