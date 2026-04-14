class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()) return false;

        HashMap<Character, Integer> map = new HashMap<Character, Integer>();

        for(int i=0; i<s.length(); i++){
            char charS = s.charAt(i);
            char charT = t.charAt(i);

            map.put(charS, map.getOrDefault(charS, 0)+1);
            map.put(charT, map.getOrDefault(charT, 0)-1);
        }

        return map.values().stream().allMatch(count -> count == 0);
    }
}
