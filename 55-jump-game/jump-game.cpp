class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        { if(i>maxi)
        {break;}
           int a= i+nums[i];
           maxi=max(a,maxi);
        }
        return (maxi>=nums.size()-1);

        
    }
};