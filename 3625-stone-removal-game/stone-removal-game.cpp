class Solution {
public:
    bool canAliceWin(int n) {
        int x=0;
        int cnt=10;
        while ( n>=cnt){
            n-=cnt;
            x=1-x;
            cnt--;
        }
        return x;
        
    }
};