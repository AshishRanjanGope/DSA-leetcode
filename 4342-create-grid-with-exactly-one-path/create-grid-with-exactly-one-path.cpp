class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>v;
        for (int i=0;i<m;i++){
            string a="";

            for(int j=0;j<n;j++){
                if (i ==0 || j==n-1){
                    a+='.';
                    continue;
                }
                a+="#";


            }
            v.push_back(a);
        }
        return v;
        
    }
};