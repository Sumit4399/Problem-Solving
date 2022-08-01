class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        sort(grades.begin(), grades.end());
        int res=0;
        int prev_sum=0, curr_sum=0, prev_count=0, curr_count=0;
        
        for(int grade: grades)
        {
            curr_sum+= grade;
            curr_count++;
            
            if(curr_sum> prev_sum && curr_count > prev_count)
            {
                res++;
                prev_sum= curr_sum;
                prev_count= curr_count;
                curr_sum = curr_count =0;
            }
        }
        return res;
    }
};