class Solution {
public:
    
 
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
//         int count=0;
        
//         vector<int>v;
//         sort(intervals.begin(), intervals.end());
//         for(int i=0; i<size(intervals); i++)
//         {
//             v.push_back(intervals[i].first);
//         }
        
// //         int r=intervals.size();
// //         int c=intervals[0].size();
        
//         sortcol(intervals.size(), intervals[0].size());
        
        int count=0; 
        int n=intervals.size();
        for(int i=0;i<n;i++) 
        {
            if(intervals[i][0]==-1)
                continue;
            
            for(int j=0;j<n;j++)
            {
                if(i==j||intervals[j][0]==-1) 
                    continue;
                else if((intervals[i][0]<=intervals[j][0])&&(intervals[j][1]<=intervals[i][1]))
                {
                    intervals[j][0]=-1;
                    count++;
                }
            }
        }
        
        int left_uncovered=n-count; 
        return left_uncovered;
    }
};