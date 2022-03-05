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
class Solution {
public:
    
    
     int find(TreeNode* root, int &k) {
          
            if (!root) return -1;
            // We do an inorder traversal here. 
            int k1 = find(root->left, k);
            if (k == 0) return k1; // left subtree has k or more elements.
            k--; 
            if (k == 0) return root->val; // root is the kth element.
            return find(root->right, k); // answer lies in the right node.
        }

        int kthSmallest(TreeNode* root, int k) {
           return find(root, k); // Call another function to pass k by reference.
        }
        

    
};