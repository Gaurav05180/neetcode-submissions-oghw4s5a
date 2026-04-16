class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;

        unordered_set<int> numSet(nums.begin(), nums.end());

        for(int num : numSet){
            int numToFind = num-1, count = 1;

            while(numSet.find(numToFind)!=numSet.end()){
                count++;
                numToFind--;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};
