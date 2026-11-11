class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         // applying concept of diff array;
        vector<int> diff(1000, 0);

        int r = trips.size();

        for (int i = 0; i < r; i++) {
            int val= trips[i][0];
            int idx1= trips[i][1];
            int idx2= trips[i][2];

            diff[idx1]+= val;
            if (idx2<1000){

            diff[idx2]-= val;
            }
        }

        // prefix sum
         for (int i = 1; i < 1000; i++) {
            diff[i]= diff[i]+diff[i-1];

         }
            
         //check if any element in diff > capacity
         for (int i = 0; i < 1000; i++) {
            if (diff[i]>capacity){
                
                return false;
            }

         }

        return true;
        
    }
};