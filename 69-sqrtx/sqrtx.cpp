class Solution {
public:
    int mySqrt(int x) {
        long long int i=1;
        while( i*i<=x){
            i*=(i+1);
        }
        i/=i+1;
        while(i*i<=x){
            i++;
        }
        return --i;

        
    }
};