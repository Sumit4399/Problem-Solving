class Solution {
public:
    vector<int> twoSum(vector<int>& num, int tar) {
        
        int i=0;
        int j= num.size()-1;
        vector<int> res;
        
        while(i<j)
        {
            if(num[i]+num[j] > tar)
            {
                j--;
            }
            else if(num[i]+num[j] < tar)
            {
                i++;
            }
            else
            {
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
        }
        return res;
    }
};