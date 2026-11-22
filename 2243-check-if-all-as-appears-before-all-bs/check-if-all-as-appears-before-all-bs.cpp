class Solution {
public:
    bool checkString(string s) {
        bool b_arrived=false;
        for ( int i=0;i<s.size();i++){
            if (b_arrived&& s[i]=='a'){
                return false;
            }
            if (s[i]=='b'){
                b_arrived= true;
            }
        }
        return true;
        
    }
};