class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9 * num < sum) {
            return "";
        }
        string ans = "";

        for (int i = 0; i < num; i++) {
            if (sum >= 9) {
                ans += '9';
                sum -= 9;
            } else  {
                ans += sum +'0';
                sum = 0;
            }
        }
    return ans;
    }
};