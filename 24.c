/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void insert(struct TreeNode *root, struct TreeNode *node)
{
  if (node->val < root->val)
  {
    if (root->left)
      insert(root->left, node);
    else
      root->left = node;
  }
  else if (node->val > root->val)
  {
    if (root->right)
      insert(root->right, node);
    else
      root->right = node;
  }
}

struct TreeNode *createNode(int val)
{
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;

  return node;
}

struct TreeNode *bstFromPreorder(int *preorder, int preorderSize)
{
  struct TreeNode *root = createNode(preorder[0]);

  for (int i = 1; i < preorderSize; i++)
  {
    struct TreeNode *node = createNode(preorder[i]);
    insert(root, node);
  }

  return root;
}