class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()<3) return nums.size();
        int maxlength = 0;

        int i = 0;
        vector<vector<int>> idx(501);
        for(int j = 0; j<n; j++) {
            cout << j;
            //check
            for(int k = j-1; k>i; k--){
                int diff = abs(nums[k]-nums[j]);
                int sum = nums[k]+nums[j];
                if(!idx[diff].empty()){
                    if((idx[diff].back()==k && idx[diff].size()>1)){
                        int indx = idx[diff][idx[diff].size()-2];
                        // cout << "hey";
                        if(indx>=i){
                            i = indx+1;
                            // continue;
                        }
                    } else if((idx[diff].back()!=k)){
                        int indx = idx[diff].back();
                        if(indx>=i){
                            i = indx+1;
                            // continue;
                        }
                    }
                }
                if(sum>500) continue;
                if(!idx[sum].empty()){
                    if((idx[sum].back()==k && idx[sum].size()>1)){
                        int indx = idx[sum][idx[sum].size()-2];
                        if(indx>=i){
                            i = indx+1;
                            continue;
                        }
                    }else if(idx[sum].back()!=k){
                        int indx = idx[sum].back();
                        if(indx>=i){
                            i = indx+1;
                            continue;
                        }
                    }
                }
            }

            //update max
            maxlength = max(maxlength, j-i+1);
            //put [j] in idx
            idx[nums[j]].push_back(j);
        }
        return maxlength;

    }
};