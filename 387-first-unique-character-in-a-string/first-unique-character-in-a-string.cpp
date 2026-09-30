class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                q.push(i);
            }
            mp[s[i]]++;
            while(q.size()>0 && mp[s[q.front()]]>1){
                q.pop();
            }
        }
        return (q.empty())?-1:q.front();
        
    }
};