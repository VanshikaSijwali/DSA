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
    void flatten(TreeNode* root) {
    
        stack<TreeNode*>st;
        TreeNode*prev=new TreeNode();
        st.push(root);
        while(root!=NULL&&!st.empty())
        {
            prev->right=st.top();
            prev=prev->right;
            st.pop();
            if(prev->right)
           { st.push(prev->right);}
           if(prev->left)
          {  st.push(prev->left);}

       prev->left=NULL;

        }
        
        
    }
};