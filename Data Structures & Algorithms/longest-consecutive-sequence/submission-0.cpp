class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;

        unordered_set<int> numSet(nums.begin(), nums.end());

        for(int num : numSet){
            int numToFind = num, count = 1;

            while(numSet.find(numToFind-1)!=numSet.end()){
                count++;
                numToFind--;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};
