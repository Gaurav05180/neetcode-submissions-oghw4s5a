class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        for(int num : nums){
            map.put(num, map.getOrDefault(num, 0)+1);
        }

        int n = nums.length;

        List<List<Integer>> v = new ArrayList<>(n+1);
        for (int i = 0; i <= n; i++) v.add(new ArrayList<>());

        for(Map.Entry<Integer, Integer> entry : map.entrySet()){
            v.get(entry.getValue()).add(entry.getKey());
        }

        int[] ans = new int[k];
        int count = 0;

        for(int i=n; i>=0; i--){
            List<Integer> arr = v.get(i);

            for(int num : arr){
                ans[count++] = num;
                if(count == k) return ans;
            }
        }

        return ans;      

    }
}