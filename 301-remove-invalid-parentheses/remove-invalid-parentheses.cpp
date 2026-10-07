class Solution {
public:
   
    void solve(int idx, string& s,int cnt , unordered_set <string>& st,string &temp,int& maxlen){
        //base case
        if (cnt<0) return;
        if (idx==s.size()){
            if (cnt==0){
                if (temp.size()> maxlen){
                    maxlen=temp.size();
                    st.clear();

                }
                if (temp.size()== maxlen){
                    st.insert(temp);
                }
            }
            return;
        }
        temp.push_back(s[idx]);
        
        int nextCnt = cnt + (s[idx] == '(' ? 1 : (s[idx]== ')' ? -1 : 0));
        solve(idx + 1, s, nextCnt, st, temp, maxlen);

        temp.pop_back();

        //skip current character (ONLY if it is a parenthesis)
        
        if (s[idx] == '(' || s[idx] == ')') {
            solve(idx + 1, s, cnt, st, temp, maxlen);
        }
        



    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set <string> st;
        string temp="";
        int maxlen =0;//pass by reference , so this is imp....solve(....,0 )->wrong
        solve (0,s,0,st,temp,maxlen);
        vector<string> v(st.begin(),st.end());
        return v;
        
    }
};