class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;

        unordered_set<int> numSet(nums.begin(), nums.end());

        for(int num : numSet){
            int currentNum = num, count = 1;

            if(numSet.find(currentNum-1)==numSet.end()){
                while(numSet.find(currentNum+1)!=numSet.end()){
                    count++;
                    currentNum++;
                }
                ans = max(ans, count);
            }
        }

        return ans;
    }
};
