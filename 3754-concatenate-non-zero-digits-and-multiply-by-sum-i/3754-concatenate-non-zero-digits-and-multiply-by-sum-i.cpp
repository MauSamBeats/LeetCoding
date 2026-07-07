class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n){
        ll sum = 0;
        string ans;
        string s = to_string(n);
        for(int i=0; i<s.size(); i++){
            if(s[i]!='0') {sum+=s[i]-'0'; ans.push_back(s[i]);}
        } 
        if(ans.empty()) return 0;
        return stoll(ans)*sum;
    }
};