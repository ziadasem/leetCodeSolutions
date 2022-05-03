.
#include <iostream>
using namespace std ;

class Solution {
public:
  int maxDepth(TreeNode* root) {
        return recMaxDepth(root);
    }
    int recMaxDepth (TreeNode* root){
        if (root ==  nullptr){
            return 0;
        }

        return 1 +getMax(recMaxDepth(root->left) , recMaxDepth(root->right)); ;
    }
    int getMax(int a, int b){
        if (a > b){
            return a;
        }
            return b ;
    }
};

