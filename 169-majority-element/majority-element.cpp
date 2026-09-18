class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        sort(nums.begin(),nums.end());//2,3,3
        vector<vector<int>> ans;

        
        for(int i=1;i<nums.size();i++){
            int count=0;
            while(i<nums.size() && nums[i]==nums[i-1]){
                count++;
                i++;
            }
            ans.push_back({nums[i-1],count});
        }
        //loop to find which one is highest
        int max_=INT_MIN;
        for(int i=0;i<ans.size();i++){
            max_=max(max_,ans[i][1]);
        }
        //loop to find which had the highest
        for(int i=0;i<ans.size();i++){
            if(ans[i][1]==max_)
            return ans[i][0];
        }
        return 0;
        
    }
};