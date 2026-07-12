class Solution {
public:
    string simplifyPath(string path) {
        string result="";
        stack<string> st;
        string temp= "";
        for(char x:path){
            if(x=='/'){
                if(temp.empty()) ;
                else if(temp==".") ;
                else if(temp==".."){
                    if(!st.empty()) st.pop();
                }else st.push(temp);
                temp.clear();
            }else temp+=x;
        }
        if(temp.empty()) ;
        else if(temp==".") ;
        else if(temp==".."){
            if(!st.empty()) st.pop();
        }else st.push(temp);

        while(!st.empty()){
            result="/"+st.top()+result;
            st.pop();
        }
        if(result.size()==0) return "/";
        return result;
    }
};