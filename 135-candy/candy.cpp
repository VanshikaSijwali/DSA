class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>temp(ratings.size(),0);
        temp[0]=1;
        
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {temp[i]=temp[i-1]+1;
            }
            else
            {temp[i]=1;
                }
        }
        for (int i = temp.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                temp[i] = max(temp[i], temp[i+1] + 1);
            }
        }
            int sum=0;
            for(int i=0;i<temp.size();i++)
            {sum+=temp[i];}
            return sum;
        
        
    }
};