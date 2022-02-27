class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int n= sentence.length();
        string t="";
        int c=1;
        int i=0;
        bool flag= false;
        
        while(i<n)
        {
            if(sentence[i]!=' ')
            {
                t+= sentence[i];
                if(t==searchWord)
                {
                    flag=true;
                    break;
                }
            }
            else
            {
                c++;
                t="";
            }
            
            i++;
        }
        
          return (flag==true? c : -1);
    }
};