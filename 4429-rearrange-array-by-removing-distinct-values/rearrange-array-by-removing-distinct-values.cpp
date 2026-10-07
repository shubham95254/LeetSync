class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mpp;
        int maxfreq = 0;
        for(auto it:nums) {
            mpp[it]++;
            maxfreq = max(mpp[it], maxfreq);
        }
        for(int i=0; i<maxfreq; i++){
            for(auto it:mpp) {
                if(mpp[it.first]>0) ans.push_back(it.first);
                mpp[it.first]--;
            }
        }
        return ans;
    }
};