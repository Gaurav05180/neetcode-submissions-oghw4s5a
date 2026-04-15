class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;

        int low = 0, high = heights.size()-1;

        while(low < high){
            int minHeight = min(heights[low], heights[high]);

            maxArea = max(maxArea, minHeight * (high-low));

            if(minHeight == heights[low]) low++;
            else high--;
        }

        return maxArea;
    }
};
