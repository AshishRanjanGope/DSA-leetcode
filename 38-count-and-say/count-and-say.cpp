#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string s = "1";

        //n-1
        for (int idx = 1; idx < n; idx++) {
            string next_s = "";
            int i = 0;
            int len = s.length();

            while (i < len) {
                int count = 1;
                // Count consec identical char
                while (i + 1 < len && s[i] == s[i + 1]) {
                    count++;
                    i++;
                }
                // freq+ char
                next_s += to_string(count) + s[i];
                i++;
            }
            s = next_s;
        }

        return s;
    }
};