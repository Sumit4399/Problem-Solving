class Solution {
public:
    int largestInteger(int num) {
        
        priority_queue<int> even;
        priority_queue<int> odd;
        string s= to_string(num);
        int n= s.size();
        
        for(int i=0; i<n; i++)
        {
            int x= s[i]-'0';
            if(x%2==0)
                even.push(x);
            else
                odd.push(x);
        }
        
        int res=0;
        for(int i=0; i<n; i++)
        {
            res=res*10;
            if(s[i]%2==0)
            {
                res+= even.top();
                even.pop();
            }
            else
            {
                res+= odd.top();
                odd.pop();
            }
        }
        return res;
    }
};