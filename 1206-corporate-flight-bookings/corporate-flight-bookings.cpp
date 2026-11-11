class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // applying concept of diff array;
        vector<int> diff(n, 0);

        int r = bookings.size();

        for (int i = 0; i < r; i++) {
            int idx1= bookings[i][0];
            int idx2= bookings[i][1];
            int val= bookings[i][2];

            diff[idx1-1]+= val;
            if (idx2<n){

            diff[idx2]-= val;
            }
        }

        // prefix sum

       

         for (int i = 1; i < n; i++) {
            diff[i]= diff[i]+diff[i-1];

         }
         return diff;

    }
    };