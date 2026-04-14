class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        int[] ans = new int[2];
        
        for(int i=0; i<nums.length; i++){
            if(map.containsKey(target-nums[i]) && map.get(target-nums[i]) != i){
                ans[0] = map.get(target-nums[i]);
                ans[1] = i;
                return ans;
            }
            else map.put(nums[i], i);
        }

        return ans;
    }
}
