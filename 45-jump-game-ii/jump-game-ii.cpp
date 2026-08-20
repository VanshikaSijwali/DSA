class Solution {
public:
int maxi=1001*10000;
int minway(vector<int>&dp,int i,vector<int>&nums)
{   if(i>=nums.size()-1)
    {return 0;}
    if(dp[i]!=-1)
    {return dp[i];}
    //dp[i]
    //1
    
    
     if(nums[i]==0)
    {dp[i]=maxi;}
    //2
    else
    {int k=nums[i];
    int mini=maxi;
    for(int j=1;j<=k;j++)
    {
        mini=min(mini,minway(dp,i+j,nums)+1);
    }
    dp[i]=mini;}
    return dp[i];
}
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);

        return minway(dp,0,nums);
        
    }
};