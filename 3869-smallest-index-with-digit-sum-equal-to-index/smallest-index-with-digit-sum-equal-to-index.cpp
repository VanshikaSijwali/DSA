class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<i)
            {continue;}
            int k=nums[i],sum=0;
            while(k!=0)
            {
                if(sum>i)
                {break;}
                sum+=k%10;
                k=k/10;
            }
            if(sum==i)
            {return i;}
        }
        return ans;
    }
};