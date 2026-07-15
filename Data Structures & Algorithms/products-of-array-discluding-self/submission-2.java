class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] products = new int[nums.length];
        int allNumsProduct = 1;
        int countZeros = 0;
        for(int i=0; i<nums.length; ++i){
            if(nums[i] == 0){
                countZeros++;
                continue;
            }
            allNumsProduct *= nums[i];
        }
        System.out.println(allNumsProduct);
        if(countZeros >0){
            for(int i=0; i<nums.length; ++i){
                if(nums[i] == 0 && countZeros ==1)products[i] = allNumsProduct;
                else products[i] =0;
            }
             return products;    
        }
        for(int i=0; i<nums.length; ++i){
            products[i] = allNumsProduct/nums[i];
        }
        return products;
    }
}  
