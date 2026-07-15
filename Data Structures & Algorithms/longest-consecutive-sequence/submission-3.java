class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0) return 0;
    Arrays.sort(nums);
    int longestCount =1;
    int curCount =1;
    for(int i=1; i<nums.length; ++i){

        if (nums[i] == nums[i - 1]) {
            continue;
        }

        if (nums[i] == nums[i - 1] + 1) {
            curCount++;
        } else {
            longestCount = Math.max(longestCount, curCount);
            curCount = 1;     
        }

    }
    return Math.max(longestCount, curCount);
    }
}
