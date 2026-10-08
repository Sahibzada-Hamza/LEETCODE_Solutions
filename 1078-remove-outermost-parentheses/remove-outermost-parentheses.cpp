class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<vector<char>> ans;
        vector<char> vec;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            vec.push_back(s[i]);
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
            if(st.empty()){
                ans.push_back(vec);
                vec.clear();
            } 
        }
        
        string ans_in="";
        for(int i=0;i<ans.size();i++){
            for(int j=1;j<ans[i].size()-1;j++){
                ans_in+=ans[i][j];
            }
        }
        return ans_in;
    }
};