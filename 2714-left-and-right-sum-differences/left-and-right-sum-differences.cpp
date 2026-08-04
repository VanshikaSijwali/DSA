class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans;
        int leftsum=0;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(leftsum);
            leftsum+=nums[i];

        }
        int rightsum=0;
        for(int i=ans.size()-1;i>=0;i--)
        {
            ans[i]=abs(ans[i]-rightsum);
            rightsum+=nums[i];
        }
        return ans;
        
    }
};