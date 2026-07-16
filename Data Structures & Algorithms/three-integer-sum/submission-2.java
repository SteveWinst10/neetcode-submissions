class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int[] sortedNums = nums.clone();
    Arrays.sort(sortedNums);
    int l;int r;
    List<List<Integer>> result = new ArrayList<>();
    for(int i=0;i<nums.length;++i) {
        if (i > 0 && sortedNums[i] == sortedNums[i - 1]) {
            continue;
        }
        l = i + 1;
        r = nums.length - 1;
        int target = -sortedNums[i];
        while (l < r) {
            if (sortedNums[l] + sortedNums[r] < target) ++l;
            else if (sortedNums[l] + sortedNums[r] > target) --r;
            else {
                result.add(Arrays.asList(-target, sortedNums[l], sortedNums[r]));
                ++l;
                --r;
                while (l < r && sortedNums[l] == sortedNums[l - 1]) l++;
                while (l < r && sortedNums[r] == sortedNums[r + 1]) r--;
            }
        }
    }
    return result;
    }
}
