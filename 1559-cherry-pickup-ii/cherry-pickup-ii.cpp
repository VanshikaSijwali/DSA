class Solution {
public:
int solve(int i,int j,int k,int &m,int &n,vector<vector<vector<int>>>&dp,vector<vector<int>>& grid)
{
   if(dp[i][j][k]!=-1)
   {return dp[i][j][k];}
    
if(i==n)
{ dp[i][j][k]=0;}
else
{
    if(j==k)
    {int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MIN, e = INT_MIN, f = INT_MIN;
        if(j>0)
        {
            if(k>0)
            {a=solve(i+1,j-1,k-1,m,n,dp,grid);}
            d=solve(i+1,j-1,k,m,n,dp,grid);
            if(k<(m-1))
            {e=solve(i+1,j-1,k+1,m,n,dp,grid);}
        }
        b=solve(i+1,j,k,m,n,dp,grid);
        if(j<(m-1))
        {    if(k<(m-1))
            c=solve(i+1,j+1,k+1,m,n,dp,grid);
            f=solve(i+1,j+1,k,m,n,dp,grid);
        }
        int abmax=max(a,b),cdmax=max(c,d),efmax=max(e,f);
        abmax=max(abmax,cdmax);
        dp[i][j][k]=grid[i][j]+max(abmax,efmax);

    }
    else
    { 

int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MIN, e = INT_MIN, f = INT_MIN, g = INT_MIN, h = INT_MIN, v = INT_MIN;
     if(j>0)
     {
        b=solve(i+1,j-1,k,m,n,dp,grid);
        if(k>0)
        {a=solve(i+1,j-1,k-1,m,n,dp,grid);}
     if(k<(m-1))
     {c=solve(i+1,j-1,k+1,m,n,dp,grid);}
     }
        
       if(k>0)
        { d=solve(i+1,j,k-1,m,n,dp,grid);}
        
         e=solve(i+1,j,k,m,n,dp,grid);
         if(k<(m-1))
        { f=solve(i+1,j,k+1,m,n,dp,grid);}
        if(j<(m-1))
        {
            h=solve(i+1,j+1,k,m,n,dp,grid);
            
        if(k>0)
        {g=solve(i+1,j+1,k-1,m,n,dp,grid);}
     if(k<(m-1))
     { v=solve(i+1,j+1,k+1,m,n,dp,grid);}
        }
        int abmax=max(a,b),cdmax=max(c,d),efmax=max(e,f),ghmax=max(g,h);
         abmax=max(abmax,cdmax);
         efmax=max(efmax,ghmax);
        int atohmax=max(abmax,efmax);
        dp[i][j][k]=grid[i][j]+grid[i][k]+max(atohmax,v);

         
         
        
    }
}


return dp[i][j][k];



}
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(71,vector<vector<int>>(71,vector<int>(71,-1)));
        int n=grid.size(),m=grid[0].size(),i=0,j=0,k=m-1;
        return solve(i,j,k,m,n,dp,grid);
        
    }
};