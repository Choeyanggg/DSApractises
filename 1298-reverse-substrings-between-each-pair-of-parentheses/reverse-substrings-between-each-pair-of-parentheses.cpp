class Solution {
public:
    string reverseParentheses(string s) {
        string str;
        for(char x:s){
            if(x!=')') str.push_back(x);
            else{
                string temp;
                while(str.back()!='('){
                    temp+=str.back();
                    str.pop_back();
                }str.pop_back();
                str+=temp;
            }
        }
        return str;
    }
};