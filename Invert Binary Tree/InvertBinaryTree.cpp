
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        recInvertTree(root);
        return root;
    }
     void recInvertTree(TreeNode* root) {
        if (root == nullptr){
            return ;
        }
        swap(root->left, root->right);
        recInvertTree(root->left);
        recInvertTree(root->right);
     }
};