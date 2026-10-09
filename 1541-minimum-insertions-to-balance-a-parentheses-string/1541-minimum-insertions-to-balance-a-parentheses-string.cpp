class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int open=0, cost=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') open++;
            else{
                if(i+1<n && s[i+1]==')'){
                    if(!open) cost++; 
                    else open--;
                    i++;
                }
                else{
                    if(!open) cost+=2;
                    else {cost++; open--;}
                }
            }
        }
        cost+=2*open; return cost;
    }
};