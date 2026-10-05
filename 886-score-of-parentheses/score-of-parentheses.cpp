class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st; // for storing prev score
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(score);
                score = 0; // reset

            } else {
                if (s[i - 1] == '(') {
                    score=st.top()+ 1;
                } else {
                    score = 2 * score+st.top();
                }
                    st.pop();
            }
        }
        return score ;
    }
};