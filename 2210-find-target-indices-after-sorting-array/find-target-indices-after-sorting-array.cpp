class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
      int eq=0,less=0;
      vector<int>ans;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]<target)
        {less++;}
        else if(nums[i]==target)
        {
            eq++;
        }
      }
      for(int i=less;i<less+eq;i++)
      {ans.push_back(i);}
      return ans;
    }
};