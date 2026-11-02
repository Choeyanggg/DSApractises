class Solution {
public:
    bool isValid(string s) {
        vector<char> start={'(','{','['};
        stack<int> st;
        for(char c:s){
            if(find(start.begin(),start.end(),c)!=start.end()){
                st.push(c);
            }else{
                if(st.empty()) return false;
                else if(c==')' && st.top()=='(') st.pop();
                else if(c==']' && st.top()=='[') st.pop();
                else if(c=='}' && st.top()=='{') st.pop();
                else return false;
            }
        }return st.empty();
    }
};