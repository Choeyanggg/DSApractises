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
                reverse(temp.begin(),temp.end());
                while(!temp.empty()){
                    str+=temp.back();
                    temp.pop_back();
                }
            }
        }
        //reverse(str.begin(),str.end());
        return str;
    }
};