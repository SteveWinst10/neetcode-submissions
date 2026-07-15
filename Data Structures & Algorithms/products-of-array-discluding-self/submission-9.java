class Solution {
    public int[] productExceptSelf(int[] nums) {
         int[] result = new int[nums.length];
        int prefix = 1; 
        for(int i=0; i<result.length; ++i){
            result[i] = prefix;
            prefix *= nums[i];
        }
        prefix =1;
        for(int i=result.length-1; i>=0; --i){
            result[i] *= prefix;
            prefix *= nums[i];
        }
        return result;
    }
}
