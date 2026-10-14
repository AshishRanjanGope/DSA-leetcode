class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9 * num < sum) {
            return "";
        }
        
        int nines = sum / 9;
        int rem = sum % 9;
        
        string ans = string(nines, '9');
        if (rem > 0) {
            ans += to_string(rem);
        }
        
        if (ans.length() < num) {
            ans.append(num - ans.length(), '0');
        }
        
        return ans;
    }
};