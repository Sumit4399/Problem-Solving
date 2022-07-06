class NumArray {
public:
    
    //helper functions
    vector<int> bit, num;
    void init(int i, int val)
    {
        i= i+1;
        while(i<= bit.size()-1)
        {
            bit[i]+= val;
            i+= i& (-i);
        }
    }
    
    int getsum(int i)
    {
        i= i+1;
        int sum=0;
        while(i>0)
        {
            sum+= bit[i];
            i-= i & (-i);
        }
        return sum;
    }
    
    NumArray(vector<int>& nums) {
        
        num = nums;
        bit.resize(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            init(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        
        int diff = val - num[i];
		num[i] = val;
		init(i, diff);
    }
    
    int sumRange(int left, int right) {
        
        return getsum(right) - getsum(left -1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */