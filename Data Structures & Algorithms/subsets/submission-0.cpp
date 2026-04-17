class Solution {
public:

    vector<vector<int>> ans;

    void find(vector<int>& nums, int i, vector<int> curr){
        if(i>=nums.size()){
            ans.push_back(curr);
            return;
        }

        find(nums, i+1, curr);
        curr.push_back(nums[i]);
        find(nums, i+1, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {      
        find(nums, 0, {});

        return ans;
    }
};
