class Solution {
public:
    bool checkPerfectNumber(int num) {
        //edge case
        if (num==1){
            return false;
        }
        long long sum=1;
        
        for(int i=2;i*i<num;i++){
            if (num%i ==0){
                sum=sum+(num/i)+i;

            }
            

        }
        return sum== num;
    }
};