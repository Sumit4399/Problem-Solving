class Solution {
public:
    
    // Floyd Algo
    int findDuplicate(vector<int>& nums) {
        int tom= nums[0];
        int jerry= nums[0];
        
        do{
            tom=nums[tom];
            jerry= nums[nums[jerry]];
        }
        while(tom!=jerry);
        
        tom=nums[0];
        while(tom!=jerry){
            tom=nums[tom];
            jerry= nums[jerry];
        }
        return jerry;
    }
};