class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.length(),sign=1;
        long long result=0;
        while(s[i]==' ' || s[i]=='_'){
            i++;
        }
        if(i==n){
            return 0;
        }
        if(i+1<n && (s[i]=='+' && s[i+1]=='-')){
            return 0;
        }
        if(s[i]=='+'){
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            result=result*10 +(s[i]-'0');
            if(result*sign > INT_MAX){
                return INT_MAX;
            }
            if(result*sign < INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return sign*result;

        
    }
};