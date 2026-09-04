class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suffmin(n);
        suffmin[n-1]=nums[n-1];
        int mini=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<mini)
            {
                mini=nums[i];

            } 
            suffmin[i]=mini;
            

        }
        int smallest=n+1;
        int maxi=nums[0];
        suffmin[0]=maxi-suffmin[0];
        if(suffmin[0]<=k)
        {smallest=0;}
        for(int i=1;i<n;i++)
        {
            if(nums[i]>maxi)
            {maxi=nums[i];}
            suffmin[i]=maxi-suffmin[i];
            if(suffmin[i]<=k)
            {
                smallest=min(smallest,i);

            }


        }
        if(smallest>n)
        {return -1;}
        return smallest;
        
    }
};