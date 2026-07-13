class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int depth=0;
        for(char x: s){
            if(x=='('){
                if(depth>0) res+=x;
                depth++;
            }else if(x==')') {
                depth--;
                if(depth>0) res+=x;
            }
        }
        return res;
    }
};