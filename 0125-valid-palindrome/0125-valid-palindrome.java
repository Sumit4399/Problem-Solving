class Solution {
    public boolean isPalindrome(String s) {
        
//         String str= s.toUpperCase();
        
//         for(int i=0; i<s.length(); i++)
//         {
//             if(s.charAt(i) != " ")
//             {
//                 str= str+ s.charAt(i);
//             }
//         }
//         System.out.println(str);
        
        String str = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        int i=0;
        int j=str.length() -1;
        
        while(i<j)
        {
            if(str.charAt(i) == str.charAt(j))
            {
                i++;
                j--;
            }
            else
            {
                return false;
            } 
        }
        return true;
    }
}