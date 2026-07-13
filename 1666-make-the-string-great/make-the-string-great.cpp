class Solution {
public:
    string makeGood(string s) {
        string res;
        for(char x: s){
            if(res.empty()) res.push_back(x);
            else if(tolower(res.back())==tolower(x) && res.back()!=x){
                res.pop_back();
            }else res.push_back(x);
        }
        return res;
    }
};