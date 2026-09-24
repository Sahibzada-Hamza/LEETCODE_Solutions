class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pregre(n,0);
        pregre[0]=height[0];
        for(int i=1;i<n;i++){
            pregre[i]=max(height[i],pregre[i-1]);
        }
        vector<int> nextgre(n,0);
        nextgre[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            nextgre[i]=max(height[i],nextgre[i+1]);
        }
        int trap=0;
        for(int i=0;i<n;i++){
            if(min(nextgre[i],pregre[i])!=0){
                trap+=min(nextgre[i],pregre[i])-height[i];
            }
        }
        return trap;

        
    }
};