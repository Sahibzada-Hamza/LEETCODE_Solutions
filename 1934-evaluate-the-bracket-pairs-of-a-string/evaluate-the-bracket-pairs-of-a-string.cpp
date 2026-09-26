class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        // putting all in map

        unordered_map<string,string> map;
        for(int i=0;i<know.size();i++){
            map[know[i][0]]=know[i][1];
        }
        //initializing
        string ans="";
        string key="";
        bool inbracket=false;
        //loop for function
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                inbracket=true;
                key="";
            }
            else if(s[i]==')'){
                inbracket=false;
                if(map.find(key)!=map.end()){
                    ans+=map[key];
                }
                else{
                    ans+="?";
                }
            }
            else{
                if(inbracket){
                    key+=s[i];
                }
                else{
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};