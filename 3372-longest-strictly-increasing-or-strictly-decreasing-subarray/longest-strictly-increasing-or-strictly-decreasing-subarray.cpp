class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> how(n,1);
        int countin=1,countdec=1;
        int longest=0;
        for(int i=0;i<n;i++){
            int j=i;
            int k=i;
            while(j+1<n && nums[j]>nums[j+1]){
                countin++;
                j++;
            }
            while(k+1<n && nums[k]<nums[k+1]){
                countdec++;
                k++;
            }
            longest=(longest>=countin&&longest>=countdec)?longest:(countin>countdec)?countin:countdec;
            countin=1;
            countdec=1;
        }
        return longest;

        
    }
};