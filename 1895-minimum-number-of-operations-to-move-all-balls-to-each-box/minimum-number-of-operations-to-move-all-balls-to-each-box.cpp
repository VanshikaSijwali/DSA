class Solution {
public:
    vector<int> minOperations(string boxes) {
        int curr=0,contrib=0;
        int next=curr+contrib;
        vector<int>ans(boxes.size(),0);
        for(int i=boxes.size()-1;i>=0;i--)
        {
            ans[i]=next;
            if(boxes[i]=='1')
            {contrib++;}
            curr=ans[i];
            next=curr+contrib;
        }
        curr=0,contrib=0;
         next=curr+contrib;
        for(int i=0;i<boxes.size();i++)
        {
            

            ans[i]+=next;
            if(boxes[i]=='1')
            {contrib++;}
            curr=next;
            next=curr+contrib;
        }
        return ans;
    }
};