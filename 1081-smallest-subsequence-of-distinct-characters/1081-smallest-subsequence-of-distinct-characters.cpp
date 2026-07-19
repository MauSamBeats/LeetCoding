class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int> lastocc(26,-1);
        for(int i=n-1; i>=0; i--){
            if(lastocc[s[i]-'a']==-1){
                lastocc[s[i]-'a']=i;
            }
        }
        stack<char> st;
        set<char> visited;
        for(int i=0; i<n; i++){
            if(visited.find(s[i])!=visited.end()) continue;
            while(!st.empty() && st.top()>s[i] && lastocc[st.top()-'a']>i){
                visited.erase(st.top());
                st.pop();
            }
            visited.insert(s[i]);
            st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};