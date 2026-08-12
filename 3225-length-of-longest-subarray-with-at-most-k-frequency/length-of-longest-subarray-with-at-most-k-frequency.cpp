class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
      map<int,int>mp;
      int start=0,end=0;
      int maxlen=0;
       while(start<=end&&end<nums.size())
      {
        if(mp.find(nums[end])!=mp.end())
        {
            if(mp[nums[end]]==k)
            { 
                maxlen=max(maxlen,end-start);
                while(nums[start]!=nums[end])
                {
                    if(mp[nums[start]]>1)
                    {mp[nums[start]]--;}
                    else
                    {mp.erase(nums[start]);}
                    start++;
                }
                start++;
                end++;

            }
            else
            {
                mp[nums[end]]++;
                end++;
            }

        }
        else
        {
            mp[nums[end]]++;
            end++;
        }
      } 
      maxlen=max(maxlen,end-start);
      return maxlen; 
    }
};