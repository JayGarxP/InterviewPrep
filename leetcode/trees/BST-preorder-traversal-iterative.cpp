/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // exit early if bad arg
        
        
        vector<int> nodeVals;
        // pre order;
        // strt treeN stack off & trav w/ root
        stack<TreeNode*> treee;
        treee.push(root);
        TreeNode* trav = root;
        
        if (root == NULL) 
            return nodeVals;
        
        while (treee.empty() == false)
        {
            if (treee.top() != NULL)
            {
            trav = treee.top();
            treee.pop();
            nodeVals.push_back(trav->val);
            }
           // push right nodes onto stack FIRST
            if (trav->right != NULL)
            {
                treee.push(trav->right);
            }
             if (trav->left != NULL)
            {
            treee.push(trav->left);
            }
        }
        
        return nodeVals;
    }
};