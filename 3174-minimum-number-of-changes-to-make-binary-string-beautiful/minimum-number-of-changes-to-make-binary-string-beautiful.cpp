class Solution {
public:
    int minChanges(string s) {
        int n= s.size();
        int cnt=0; // thought process : smallest even partition is 2(each). so , check in it
        for( int i=0;i<n-1;i+=2){
            if (s[i]!=s[i+1]){
                cnt++;

            }
        }

        return cnt;
    }
};