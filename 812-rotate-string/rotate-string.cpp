class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.length();i++){
            int key=s[0];
            s.erase(0,1);
            s.push_back(key);
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};