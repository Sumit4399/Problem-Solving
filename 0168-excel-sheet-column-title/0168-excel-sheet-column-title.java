class Solution {
    public String convertToTitle(int n) {
        
        String s="";
        n--;
        
        while(n>=0)
        {
            char ch='A';
            int num=n%26;
            ch=(char)(ch+num);
            s+=ch;
            n/=26;
            n--;
        }
        
        StringBuilder str= new StringBuilder(s);
        str.reverse();
        
        return str.toString();
    }
}