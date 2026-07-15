class Solution {
    public boolean isPalindrome(String s) {
        char[] str = s.toLowerCase().toCharArray();
    int l=0; int r = s.length()-1;
    boolean palindrome = true;
    while(l<r){
        while(!Character.isLetterOrDigit(str[l]) && l<r){
            ++l;
        }
        while(!Character.isLetterOrDigit(str[r]) && r>l){
            --r;
        }
        if(str[l] != str[r]){
            
            palindrome = false;
        }
        ++l; --r;
    }
    return palindrome;
    }
}
