class Solution {
public:
    void helper(string& s, int curr, int next, vector<int>& ans, int high, int low){
        if(curr%10==9){
            if(curr>=low && curr<=high)ans.push_back(curr);
            if(s.back()=='9') return;
            s.push_back(s.back()+1);
            return helper(s,stoi(s),next*10+1,ans,high,low);
        }
        if(curr>high) return;
        if(curr>=low) ans.push_back(curr);
        return helper(s,curr+next,next,ans,high,low);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int begin = log10(low)+1;
        string s;
        int next = 0;
        for(int i=0; i<begin; i++){
            s.push_back(i+1+'0');
            next=next*10+1;
        }
        helper(s,stoi(s),next,ans,high,low);
        return ans;
    }
};