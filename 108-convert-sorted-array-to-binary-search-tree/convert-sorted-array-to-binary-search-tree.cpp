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
TreeNode* build(vector<int>&nums,int start,int end)
{
    if(start>end)
    {return NULL;}
    int mid=start+(end-start)/2;
    TreeNode*new1=new TreeNode(nums[mid]);
    new1->left =build(nums,start,mid-1);
    new1->right=build(nums,mid+1,end);
   
    return new1;
}


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        return build(nums,start,end);
        
    }
};