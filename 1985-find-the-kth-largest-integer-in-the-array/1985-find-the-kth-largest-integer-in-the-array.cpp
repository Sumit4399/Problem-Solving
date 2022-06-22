class Solution {
public:
    
//     struct comparator{
        
//     bool operator()(string &s1, string&s2){
//         if(s1.length()>s2.length())
//             return false;
//         else if(s1.length()<s2.length())
//             return true;
        
//         else{
            
//             for(int i=0; i<s1.size(); i++){
//                 if(s1[i]-'0'>s2[i]-'0')
//                     return false;
//                 else if(s1[i]-'0'<s2[i]-'0')
//                     return true;
//             }
//         }
//         return true;
//     }
// };
    
 //   string kthLargestNumber(vector<string>& nums, int k) {
        
//         priority_queue<int> pq;
//         vector<int> v;
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             int temp= stoll(nums[i]);
//             v.push_back(temp);
//         }
        
//         for(int i=0; i<v.size(); i++)
//         {
//             pq.push(v[i]);
//         }
        
//         while(k-1>0)
//         {
//             pq.pop();
//             k--;
//         }
        
//         string ans= to_string(pq.top());
//         return ans;
        
        
//         priority_queue<string, vector<string>, comparator>pq;
//         for(auto it:nums)
//         {
//             pq.push(it);
//         }
        
//         while(k-1>0)
//         {
//             pq.pop();
//             k--;
//         }
//         return pq.top();
//     }
    
    
    struct comparator{
        
    bool operator()(string &s1, string&s2){
        if(s1.length()<s2.length())
            return true;
        else if(s1.length()>s2.length())
            return false;
        
        else{
            
            for(int i=0; i<s1.size(); i++){
                if(s1[i]-'0'<s2[i]-'0')
                    return true;
                else if(s1[i]-'0'>s2[i]-'0')
                    return false;
            }
        }
        
        return false;
    }
};
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        //min heap
        priority_queue<string, vector<string>, comparator>pq;
        string ans;
        
        for(auto it:nums)
        {
            pq.push(it);
        }
        
        while(!pq.empty() && k>0)
        {
            ans=pq.top();
            pq.pop();
            k--;
        }
        
        return ans;
        
    }
};