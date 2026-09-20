class Solution {
public:
    int num(char s){
        int curr=26;
        char cha='a';
        while(cha!=s){
            cha++;
            curr--;
        }
        return curr;
    }
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            int curr=num(s[i]);
            sum+=(curr*(i+1));    
        }
        return sum;
    }
};