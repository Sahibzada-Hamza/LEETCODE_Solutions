class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a, int b){
            return abs(a)>abs(b);
        });
        long long int sum=0;
        int i=0,en=nums.size()-1;
        for(;i<en;i++,en--){
            sum+=(nums[i]*nums[i]);
            sum-=(nums[en]*nums[en]);
        }
        if(i==en){
            sum+=(nums[en]*nums[en]);
        }
        return sum;
        
    }
};