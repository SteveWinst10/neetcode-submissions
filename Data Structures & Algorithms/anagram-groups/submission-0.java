class Solution {
     public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> map = new HashMap<>();
        for(String str: strs){
            char[] sortedChar = str.toCharArray();
            Arrays.sort(sortedChar);
            String sortedStr = new String(sortedChar);
            List<String> existingAnagrams  = map.get(sortedStr);
            if(existingAnagrams == null ){
                List<String> newAnagrams = new ArrayList<>();
                newAnagrams.add(str);
                map.put(sortedStr,newAnagrams);
            }
            else {
                existingAnagrams.add(str);
            }
        }
        return new ArrayList<>(map.values());
    }
}
