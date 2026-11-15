class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map <int, int> mp; // idx , val
        mp[0]=1; // pref [-1]=0;
        vector<int> pref(n,0);
        pref[0]= nums[0];

        for( int i=1;i<n;i++){
            pref[i]= nums[i]+pref[i-1];
        }

        long long ans=0;
        for( int i=0;i<n;i++){
            int tofind = pref[i]- k;



                auto it = mp.find(tofind);
            if (it!= mp.end()){
                ans+=it->second;

            }
            mp[pref[i]]++;

            




        }
        return ans;
        
    }
};