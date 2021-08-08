class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merg;
        
        merg.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++)
        {
            int size= merg.size()-1;
            if(intervals[i][0]<=merg[size][1])
                merg[size][1]= max(merg[size][1], intervals[i][1]);
            
            else
                merg.push_back(intervals[i]);
        }
        return merg;
    }
};