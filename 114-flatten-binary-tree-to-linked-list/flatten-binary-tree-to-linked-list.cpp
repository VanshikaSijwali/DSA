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
void solve(TreeNode* root)
{
    if(root==NULL)
    {return;}
    TreeNode*temp=root->right;
    root->right=root->left;
    root->left=NULL;
    solve(root->right);
    TreeNode*ptr=root;
    while(ptr->right!=NULL)
    {ptr=ptr->right;}
    ptr->right=temp;
    solve(temp);

}
    void flatten(TreeNode* root) {
        
        solve(root);
        
        
    }
};