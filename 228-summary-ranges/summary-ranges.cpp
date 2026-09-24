class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)
        {return {};}
        int start=nums[0],end=nums[0];
        vector<string>ans;
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i-1]+1)==nums[i])
            {end=nums[i];}
            else
            {  if(start==end)
            {
                ans.push_back(to_string(start));

            }
            else
               { ans.push_back(to_string(start)+"->"+to_string(end));}
                start=nums[i];
                end=nums[i];
                
            }
        }
        if(start==end)
            {
                ans.push_back(to_string(start));

            }
            else
               { ans.push_back(to_string(start)+"->"+to_string(end));}
        return ans;
    }
};