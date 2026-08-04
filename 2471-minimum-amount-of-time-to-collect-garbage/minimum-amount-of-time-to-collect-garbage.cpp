class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int>cost;
        cost.push_back(0);
        for(int i=0;i<travel.size();i++)
        {
            cost.push_back(cost.back()+travel[i]);
        }
        int tcost=0,gpos=0,ppos=0,mpos=0;
        for(int i=0;i<garbage.size();i++)
        {
            bool g=false,m=false,p=false;
            tcost+=garbage[i].size();
            for(int j=0;j<garbage[i].size();j++)
            {
                if(g&&p&&m)
                {break;}
                if(garbage[i][j]=='G')
                {g=true;}
                else if(garbage[i][j]=='M')
                {m=true;}
                else
                {p=true;}
            }
            if(m==true)
            {
                tcost+=(cost[i]-cost[mpos]);
                mpos=i;
            }
              if(p==true)
              {
                tcost+=(cost[i]-cost[ppos]);
                ppos=i;
              }
              if(g==true)
              {tcost+=(cost[i]-cost[gpos]);
              gpos=i;}
        }
        return tcost;




    }
};