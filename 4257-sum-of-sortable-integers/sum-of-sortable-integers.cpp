class Solution {
public:
    vector<int> LPS(vector<int>& s) {
        int n = s.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool KMP(vector<int>& num, vector<int>& p) {
        vector<int> txt = num;
        txt.insert(txt.end(), num.begin(), num.end());

        int n = txt.size();
        int m = p.size();

        if (m == 0)
            return 0;

        vector<int> lps = LPS(p);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (txt[i] == p[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return true;
            } else if (i < n && txt[i] != p[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    int sortableIntegers(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int n = nums.size();
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i != 0)
                continue;
            int cnt = 0;

            for (int j = 0; j < n; j += i) {
                vector<int> vec1(nums.begin() + j, nums.begin() + j + i);
                vector<int> sorted_vec1(sorted_nums.begin() + j,
                                        sorted_nums.begin() + j + i);

                if (KMP(vec1, sorted_vec1)) {
                    cnt++;

                } else {
                    break;
                }
            }
            if (cnt == (n / i)) {
                sum += i;
            }
        }
        return sum;
    }
};