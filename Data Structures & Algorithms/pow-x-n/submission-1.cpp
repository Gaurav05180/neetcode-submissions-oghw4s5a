class Solution {
public:

    double findPow(double x, int n){
        double ans = x;

        while(--n > 0){
            ans *= x;
        }

        return ans;
    }

    double myPow(double x, int n) {
        if(n==0) return 1.0;
        else if(n<0) return 1.0/findPow(x, abs(n));
        else return findPow(x, n);
    }
};
