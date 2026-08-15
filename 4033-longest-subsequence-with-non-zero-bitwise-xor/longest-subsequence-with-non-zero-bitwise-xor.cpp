class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool check=false;
        for(int i=0;i<nums.size();i++)
        {
            if(check==false&&nums[i]!=0)
            {check=true;}
            x=x^nums[i];

        }
        if(x!=0)
        {return nums.size();}
        else
        {
            if(check)
            {return nums.size()-1;}
            else
            {return 0;}
        }
    }
};