class Solution {
    
    struct Node 
    {
        vector<Node*> children;
        Node(vector<Node*> &top) 
        {
            children = top;
        }
    };
    
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<Node*> top(26, NULL);
        for (int i = s.size() - 1; i >= 0 ; i--) 
        {
            Node * node = new Node(top); // store the current snapshot
            top[s[i] - 'a'] = node;
        }
        
        int ret = 0;
        for (auto &word : words)
        {
            bool found = isSubSeq(top, word);
            if (found)
            {
                ret++;
            }
        }
        return ret;
    }

    bool isSubSeq(vector<Node*> &top, string &word) {
        
        vector<Node*> *cur = &top;
        for (int i = 0; i < word.size(); i++)
        {
            Node* next = cur->at(word[i]-'a');
            if (!next)
            {
                return false;
            }
            cur = &next->children;
        }
        return true;
    }
};