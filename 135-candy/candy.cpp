class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
       vector<int> LR(n,1);
       vector<int> RL(n,1);

        // left to right
        for (int i = 1; i < n; i++) {
            if (rat[i - 1] < rat[i]) {
               
            LR[i] = LR[i - 1] + 1;
            }
        }
        //right to left
        for (int i = n-2; i >=0; i--) {
            if (rat[i +1] < rat[i]) {
              
               RL[i]= RL[i + 1] + 1;
            }
        }
        int sum=0;

        for (int i = 0; i < n; i++) {
            sum+=max(LR[i],RL[i]);

        }
        return sum;




    }
};