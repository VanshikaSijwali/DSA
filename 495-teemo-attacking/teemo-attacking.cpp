class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int ans=duration;
        int end=timeSeries[0]+duration;
        for(int i=1;i<timeSeries.size();i++)
        {
            if(timeSeries[i]>=end)
            {
                ans+=duration;
                end=timeSeries[i]+duration;

            }
            else
            {
              int  pseudoend=timeSeries[i]+duration;
                ans+=(pseudoend-end);
                end=pseudoend;
            }

        }
        return ans;
    }
};