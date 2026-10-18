class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i=0;i<num.size();i++){
            int x= num[i];
            while (!st.empty()&& st.top()>x && k>0){// use while instead of if  bcuz there can be many element in st.top()>x
                st.pop();
                k--;

            }
            if (st.empty() && x=='0'){
                continue; // to remove leading zeros

            }
            st.push(num[i]);
        }

        // k>0 left
        while (k>0 && !st.empty()){
            st.pop();
            k--;
        }

        // forming ans string

        string ans="";
        while (!st.empty()){
            ans+=st.top();
            st.pop();

        }
        reverse(begin(ans),end(ans));
        if(ans==""){
            return "0";
        }
        return ans;

    }
};