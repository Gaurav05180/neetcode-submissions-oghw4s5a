class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int area = 0;

        vector<int> preMax(n, 0), sufMax(n, 0);

        int prev = 0;
        for(int i=1; i<n; i++){   
            prev = max(prev, height[i-1]);         
            preMax[i] = prev;            
        }

        prev = 0;
        for(int i=n-2; i>=0; i--){
            prev = max(prev, height[i+1]);
            sufMax[i] = prev;   
                     
        }

        for(int i=0; i<n; i++){
            int minHeight = min(preMax[i], sufMax[i]);

            area += max(0, minHeight - height[i]);
        }

        return area;
    }
};
