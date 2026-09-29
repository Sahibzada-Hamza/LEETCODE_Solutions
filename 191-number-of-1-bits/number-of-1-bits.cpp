class Solution {
public:
    int hammingWeight(int n) {
        string dig="";
        while(n>0){
            if(n%2==0){
                dig='0'+dig;
            }
            else{
                dig='1'+dig;
            }
            n/=2;
        }
        int count=0;
        for(int i=0;i<dig.size();i++){
            if(dig[i]=='1'){
                count++;
            }
        }
        return count;
    }
};
