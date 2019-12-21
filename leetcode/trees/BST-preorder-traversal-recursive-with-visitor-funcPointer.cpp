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
   
        TreeNode* trav = root;
        
        //preorderTraverseVisitor(trav, nodeVals);
        
        // with function pointer visitor function
        preorderTraverseVisitor(trav, nodeVals, appendToVectorVisitor);
        
        return nodeVals;
    }
    
         // pre order wiki;
        /*
            Check if the current node is empty or null.
    Display the data part of the root (or current node).
    Traverse the left subtree by recursively calling the pre-order function.
    Traverse the right subtree by recursively calling the pre-order function.
    */
    // void preorderTraverseVisitor(TreeNode* node, vector<int> &vals)
    // {
    //     if (node != NULL)
    //     {
    //         vals.push_back(node->val);
    //         preorderTraverseVisitor(node->left, vals);
    //         preorderTraverseVisitor(node->right, vals);
    //     }
    // }
    
    static void appendToVectorVisitor(int appVal, vector<int>& vals)
    {
        vals.push_back(appVal);
    }
    
     void preorderTraverseVisitor(TreeNode* node, vector<int>& vals, void(*visitorFunc)(int, vector<int>&))
    {
        if (node != NULL)
        {
            int test = node->val;
            visitorFunc(test, vals);
            preorderTraverseVisitor(node->left, vals, visitorFunc);
            preorderTraverseVisitor(node->right, vals, visitorFunc);
        }
    }
};