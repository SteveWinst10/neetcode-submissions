class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
    for (int num : nums) {
        set.add(num);
    }
    int longest = 0;
    int curLength = 1;
    for(int num : set){
      
        if(!set.contains(num-1)) {
            curLength = 1;
            while (set.contains(num + 1)) {
                curLength++;
                num++;
            }
            longest = Math.max(longest, curLength);
        }
    }
      
    return longest;
    }
}
