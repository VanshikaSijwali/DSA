class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]>b[1];

        });
        int ans=0;
        for(int i=0;i<boxTypes.size()&&truckSize>0;i++)
        {
            int possible=boxTypes[i][0]*boxTypes[i][1];
            if(boxTypes[i][0]<=truckSize)
            {
                ans+=possible;
                truckSize-=boxTypes[i][0];
            }
            else
            {
              possible=  truckSize*boxTypes[i][1];
              ans+=possible;
              break;
            }

        }
        return ans;
    }
};