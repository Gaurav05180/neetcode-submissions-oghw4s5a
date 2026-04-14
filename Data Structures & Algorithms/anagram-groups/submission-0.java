class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<String, List<String>>();

        for(String str : strs){
            char[] charArr = str.toCharArray();
            Arrays.sort(charArr);
            String sortedStr = new String(charArr);
            if(map.containsKey(sortedStr)){
                List<String> list = map.get(sortedStr);
                list.add(str);
                map.put(sortedStr, list);
            }
            else{
                List<String> list = new ArrayList<>();
                list.add(str);
                map.put(sortedStr, list);
            }
        }


        List<List<String>> ans = new ArrayList<>();

        for(List<String> list : map.values()){
            ans.add(list);
        }

        return ans;
    }
}
