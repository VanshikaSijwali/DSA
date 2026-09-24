class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>st;
        int total=candyType.size()/2;
        for(int i=0;i<candyType.size();i++)
        {
            if(st.find(candyType[i])==st.end())
            {st.insert(candyType[i]);}
            if(st.size()>total)
            {return total;}
        }
        return st.size();
        
    }
};