class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int tot_sum=0;
        for(int num:nums){
            tot_sum+=num;
        }
        int tar=tot_sum-x;
        if(tar==0){
            return n;
        }
        if(tar<0){
            return -1;
        }
        int left=0;
        int currsum=0;
        int maxlen=-1;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            while(currsum>tar && left<=i){
                currsum-=nums[left];
                left++;
            }
            if(currsum==tar){
                maxlen=max(maxlen,i-left+1);
            }
        }
        return (maxlen==-1)?-1:n-maxlen;
        
    }
};