class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int count=1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==count)
            {count++;
                continue;}
                else if(nums[i]<count)
                {continue;}
                else
                {
                    ans.push_back(count);
                    int diff=nums[i]-count-1;
                    int j=count+1;
                    for(;j<=count+diff;j++)
                    {ans.push_back(j);}
                    count=nums[i]+1;


                }


        }
        if(count<=n)
       { for(int j=count;j<=n;j++)
        {ans.push_back(j);}}
        return ans;
    }
};