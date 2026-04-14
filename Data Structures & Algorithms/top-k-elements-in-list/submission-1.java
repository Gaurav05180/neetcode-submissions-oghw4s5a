class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        for(int num : nums){
            map.put(num, map.getOrDefault(num, 0)+1);
        }

        List<int[]> v = new ArrayList<>();

        for(Map.Entry<Integer, Integer> entry : map.entrySet()){
            v.add(new int[]{entry.getKey(), entry.getValue()});
        }

        Collections.sort(v, (a, b) -> b[1]-a[1]);

        int[] ans = new int[k];

        for(int i=0; i<k; i++){
            ans[i] = v.get(i)[0];
        }

        return ans;
    }
}
