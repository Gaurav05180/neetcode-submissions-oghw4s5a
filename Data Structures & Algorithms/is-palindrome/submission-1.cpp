class Solution {
public:

    bool isAlphanumeric(char c){
        return (c >= 'a' && c <= 'z')
                || (c >= 'A' && c <= 'Z')
                || (c >= '0' && c <= '9');
    }

    bool isMatched(char a, char b){
        if((a >= 'A' && a <= 'Z') && (b >= 'a' && b <= 'z')){
            return (a-'A'+'a') == b;
        }
        else if((a >= 'a' && a <= 'z') && (b >= 'A' && b <= 'Z')){
            return (b-'A'+'a') == a;
        }
        else return a == b;
    }

    bool isPalindrome(string s) {
        int low = 0, high = s.length()-1;

        while(low < high){
            while(!isAlphanumeric(s[low]) && low < high){
                low++;
            }

            while(!isAlphanumeric(s[high]) && low < high){
                high--;
            }

            if(!isMatched(s[low], s[high])){
                return false;
            }

            low++;
            high--;
        }

        return true;
    }
};
