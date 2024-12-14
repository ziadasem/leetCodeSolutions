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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return recIsSameTree(p, q);
    }

    bool recIsSameTree(TreeNode* p, TreeNode* q) {
        bool pIsNull = p == nullptr; 
        bool qIsNull = q == nullptr; 
        if (  (pIsNull ^qIsNull)  ){
            return false;
        }
        if (  (pIsNull  && qIsNull)  ){
            return true;
        }
        return (p->val == q->val) && recIsSameTree(p->left, q->left) && recIsSameTree(p->right, q->right);  // p and q are not null, and their values are equal, and both subtrees are the same.
    }
};