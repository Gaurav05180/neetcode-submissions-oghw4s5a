class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int[] preProd = new int[n];
        int[] posProd = new int[n];

        preProd[0] = 1;
        posProd[n-1] = 1;

        for(int i=1; i<n; i++){
            preProd[i] = preProd[i-1] * nums[i-1];
            posProd[n-1-i] = posProd[n-i] * nums[n-i];
        }

        for(int i=0; i<n; i++){
            nums[i] = preProd[i] * posProd[i];
        }

        return nums;
    }
}  
