class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() == t.length()) {
            char[] sortedS = s.toCharArray();
            Arrays.sort(sortedS);
            char[] sortedT = t.toCharArray();
            Arrays.sort(sortedT);

            for(int i=0; i<s.length(); ++i){
                if(sortedS[i] != sortedT[i]){
                    return false;
                }
            }
        }
        else {
            return false;
        }
        return true;
    }
}
