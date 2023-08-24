class Solution {
    public static boolean solve(String a,String b){
        for(int i=0;i<b.length();i+=a.length()){
            if(i+a.length()>b.length()) return false;
            if(a.equals(b.substring(i,i+a.length()))==false) return false;
        }
        return true;
    }
    public boolean repeatedSubstringPattern(String s) {
        //String s="";
        for(int i=1;i<=s.length()/2;i++)
            if(solve(s.substring(0,i),s))
                return true;
        return false;
    }
}