class Solution {
public:
int solve(int i,vector<int>&dp,vector<int>&nums)
{ if(i>=nums.size())
{return 0;}
if(dp[i]!=-1)
{return dp[i];}

if(i==nums.size()-1)
{dp[i]=1;}
else if(nums[i]==0&&i!=nums.size()-1)
{dp[i]=0;}
else
{
    int k=nums[i];
    int a=0;
    for(int j=1;j<=k;j++)
    {
        a=a||solve(i+j,dp,nums);
    }
    dp[i]=a;
}



    

    return dp[i];

}
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,dp,nums)==1;
    }
};