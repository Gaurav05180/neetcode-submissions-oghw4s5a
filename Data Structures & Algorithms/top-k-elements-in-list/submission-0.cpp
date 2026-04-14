class Solution {
public:

    static bool comp(vector<int> v1, vector<int> v2){
        return v1[1]>v2[1];
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int num : nums) map[num]++;

        vector<vector<int>> v;

        for(auto& it : map){
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), comp);

        vector<int> ans;

        for(int i=0; i<k; i++){
            ans.push_back(v[i][0]);
        }

        return ans;
    }
};
