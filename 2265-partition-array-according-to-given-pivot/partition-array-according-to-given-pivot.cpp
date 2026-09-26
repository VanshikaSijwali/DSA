class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>greater;
        int pos=0,ptr=0,count=0;
        while(ptr<nums.size())
        {
            if(nums[ptr]<pivot)
            { swap(nums[ptr],nums[pos]);

                ptr++;
                pos++;

            }
            else 
            {
                if(nums[ptr]==pivot)
                {count++;
                }
                else
                {greater.push_back(nums[ptr]);

                }
                ptr++;

            }
        }
        int j=pos;
        for(;j<pos+count;j++)
        {
            nums[j]=pivot;
        }
        for(int i=0;i<greater.size();i++)
        {
            nums[i+j]=greater[i];
        }
        return nums;
    
        
    }
};