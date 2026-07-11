class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) { 
            Integer value = map.get(target - nums[i]);
            if (value != null) {
                return new int[] {value, i};
            }
            map.put(nums[i], i);
        }
        return new int[] {0, 0};
    }
}