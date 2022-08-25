class Solution {
public:
    vector<int> plusOne(vector<int>& dit) {
        
        int n= dit.size();
        for(int i=n-1; i>=0; i--)
        {
            if(dit[i]==9)
            {
                dit[i]=0;
            }
            else
            {
                dit[i]+= 1;
                return dit;
            }
        }
        
        dit.insert(dit.begin(), 1);
        return dit;
    }
};