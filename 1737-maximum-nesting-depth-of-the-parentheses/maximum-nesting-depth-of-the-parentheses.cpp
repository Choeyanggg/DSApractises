class Solution {
public:
    int maxDepth(string s) {
        int depth=0,maxi=0;
        for(char x:s){
            if(x=='('){
                depth++;
                maxi=max(maxi,depth);
            }else if(x==')'){
                depth--;
            }
        }return maxi;
    }
};