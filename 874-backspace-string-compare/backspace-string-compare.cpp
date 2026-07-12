class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, s2;
        for(char x:s){
            if(!s1.empty() && x=='#'){
                s1.pop_back();
            }else if(s1.empty() && x=='#') continue;
            else  s1.push_back(x);
        }
        for(char x:t){
            if(!s2.empty() && x=='#'){
                s2.pop_back();
            }else if(s2.empty() && x=='#') continue;
            else s2.push_back(x);
        }
        return s1==s2;
    }
};