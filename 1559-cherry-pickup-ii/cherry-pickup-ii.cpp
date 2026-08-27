class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        int i=n-1;
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(j!=k)
                {dp[i][j][k]=grid[i][j]+grid[i][k];}
                else
                {dp[i][j][k]=grid[i][k];}
            }
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {int maxi=-1e8;
                    for(int dj1=-1;dj1<=1;dj1++)
                    {
                        for(int dj2=-1;dj2<=1;dj2++)
                        {
                            int value=0;
                            if(j==k)value=grid[i][j];
                            else value=grid[i][j]+grid[i][k];
                            if(j+dj1>=0&&j+dj1<m&&k+dj2>=0&&k+dj2<m)
                           { value+=dp[i+1][j+dj1][k+dj2];}
                           else
                           {value=-1e8;}
                            maxi=max(maxi,value);

                        }
                    }
                   
dp[i][j][k] = maxi;
                }
            }

        }

        
        return dp[0][0][m-1];

        
    }
};