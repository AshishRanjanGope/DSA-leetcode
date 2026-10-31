class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int i=1;
        int candy=n;

        while (i<n){
            //equal condn
            while(i<n && ratings[i]==ratings[i-1]){
                i++;
                

            }
            int peak=0;
            while(i<n && ratings[i]>ratings[i-1]){ //increasing
                peak++;
                candy+=peak;
                i++;

                if(i==n)return candy;

            }

            //decreasing
            int dip=0;
            while(i<n && ratings[i]<ratings[i-1]){
                dip++;
                candy+=dip;
                i++;

            }
            candy-=min(peak,dip);

        }
        return candy;
        
    }
};