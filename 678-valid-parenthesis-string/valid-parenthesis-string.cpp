class Solution {
public:
int solve(string s,int count,int i,vector<vector<int>>&dp)
{
    if(count<0)
    {return 0;}
    if(dp[i][count]!=-1)
    {return dp[i][count];}

    if(i==s.size())
    {
        if(count==0)
        {dp[i][count]=1;}
        else
        {dp[i][count]=0;}
    }
    else
    {
        if(s[i]=='(')
        {
            dp[i][count]=solve(s,count+1,i+1,dp);

        }
        else if(s[i]==')')
        {
            dp[i][count]=solve(s,count-1,i+1,dp);
        }
        else
        {
           dp[i][count]=solve(s,count+1,i+1,dp)||solve(s,count,i+1,dp)||solve(s,count-1,i+1,dp);
        }
    }
    return dp[i][count];
}
    
    bool checkValidString(string s) {
        
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,0,0,dp)==1;

        
    }
};