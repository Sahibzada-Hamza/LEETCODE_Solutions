class Solution {
public:
    bool isPalindrome(int x) {
        if (x >= 0) {
            vector<int> digits;
            int i = 0;
            while (x > 0) {
                digits.push_back(x % 10);
                x = x / 10;
                i++;
            }
            int n = digits.size();
            for (int i = 0,en=n-1; i <en; i++,en--) {
                if (digits[i] != digits[en]) {
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
};