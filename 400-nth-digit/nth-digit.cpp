class Solution {
public:
    typedef long long ll;
    int findNthDigit(int n) {
        if (n <= 9) {
            return n;
        }
        ll bucket = 9;

        ll d = 1;

        while (bucket * d < n) {
            n -= bucket * d;
            d++;
            bucket *= 10;
        }
       

        ll number = bucket/9 + (n - 1) / d;

        string s = to_string(number);

        ll ans = s[(n-1) % d] - '0';

        return ans;
    }
};