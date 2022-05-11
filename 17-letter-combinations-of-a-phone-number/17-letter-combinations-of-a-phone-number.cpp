class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.length()==0)
            return res;
        
        unordered_map<string, vector<string>> M;
        M["2"] = {"a","b","c"};
        M["3"] = {"d","e","f"};
        M["4"] = {"g","h","i"};
        M["5"] = {"j","k","l"};
        M["6"] = {"m","n","o"};
        M["7"] = {"p","q","r","s"};
        M["8"] = {"t","u","v"};
        M["9"] = {"w","x","y","z"};
        
        deque<string> dq;
        dq.push_back("");
        
        for(int i=0; i<digits.length(); i++)
        {
            string fst= "";
            fst.push_back(digits[i]);
            
            vector<string> initial= M[fst];
            int n= dq.size();
            
            for(int j=0; j<n; j++)
            {
                string dq_front= dq.front();
                
                for(int k=0; k<initial.size(); k++)
                {
                    string temp= dq_front + initial[k];
                    dq.push_back(temp);
                }
                dq.pop_front();
            }
        }
        
        while(dq.size()>0)
        {
            res.push_back(dq.front());
            dq.pop_front();
        }
        return res;
    }
};