class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int speed = high;

        while(low<=high){
            int mid = low + (high-low)/2;

            int totalTime = 0;

            for(int pile : piles){
                totalTime += ceil(static_cast<double>(pile)/mid);
            }

            if(totalTime <= h){
                speed = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return speed;
    }
};
