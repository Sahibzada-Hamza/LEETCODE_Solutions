class Solution {
public:
    bool checkString(string s) {
        int idx=-1;//first b ocrr
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                idx=i;
                break;
            }
        }
        if(idx==-1) return 1;
        for(int i=idx+1;i<s.size();i++){
            if(s[i]=='a'){
                return 0;
            }
        }
        return 1;
        
    }
};