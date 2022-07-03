class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int pos=1;
        int neg=1;
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]>nums[i-1])
            {
                pos= neg+1;
            }
            else if(nums[i] < nums[i-1])
            {
                neg= pos+1;
            }
        }
         return max(pos, neg);   
    }
};


// int inc = 1;
//         int dec = 1;
//         for(int i = 1;i<nums.size();i++){
//             if(nums[i]>nums[i-1]){
//                 inc = dec + 1;
//             }
//             else if(nums[i]<nums[i-1]){
//             // else{
//                 dec = inc + 1;
//             }
//         }
//         return max(inc,dec);