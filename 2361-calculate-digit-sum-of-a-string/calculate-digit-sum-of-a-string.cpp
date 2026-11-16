class Solution {
public:



  string sumd( string s){
    int n= s.size();
    
    int ans=0;

    for (int i=0;i<n;i++){
        ans+=s[i]-'0';

    }
    string res = to_string(ans);
    return res;


  }
    string digitSum(string s, int k) {



        while (s.size()>k){

            string st = "";
        int n= s.size();
        for( int i=0;i<n;i+=k){
            int range = min(k, n-i);

            st+=sumd(s.substr(i,range));
        }
            s= st;
        }

        return s;
        
    }
};