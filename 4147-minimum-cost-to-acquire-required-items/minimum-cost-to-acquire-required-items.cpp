class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans1;
        long long ans2;
        long long ans3;

        //pure costboth 

        if (need1>= need2){
            ans1= 1LL*need1*costBoth;
        }
        else{
            ans1= 1LL*need2*costBoth;

        }

        // costBoth upto min
         if (need1>= need2){
            ans2= 1LL*need2*costBoth+1LL*(need1-need2)* cost1;
         }
         else{
            ans2= 1LL*need1*costBoth+1LL*(need2-need1)* cost2;

         }

         // both separate 

         ans3= 1LL*need1* cost1+1LL*need2* cost2;



         return min({ans1, ans2, ans3});


        
    }
};