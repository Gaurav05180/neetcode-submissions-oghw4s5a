class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int ans = 0;

        int i=0;
        unordered_set<char> charSet;

        for(int j=0; j<s.length(); j++){
            while(charSet.find(s[j])!=charSet.end()){
                charSet.erase(s[i++]);
            }
            charSet.insert(s[j]);
            ans = max(ans, j-i+1);
        }       

        return ans;
    }
};
