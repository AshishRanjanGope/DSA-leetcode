class Solution {
public:
    bool binsearch(vector<int>& a, int tg){
        int n= a.size();

        int s= 0;
        int e= n-1;
        int mid = s + (e - s) / 2;
        while (s<=e){
           
        mid = s + (e - s) / 2;
            if (tg== a[mid]){
                return true;

            }
            else if (tg>a[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }


        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found =false;
        int n=matrix.size();

        for (int i=0;i<n;i++){
            if (binsearch(matrix[i],target)){
                found= true;
            }
        }
        return found;
        
    }
};