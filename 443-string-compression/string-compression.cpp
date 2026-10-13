class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int write=0;
        int i=0;
        while(i<n){
            char c=chars[i];
            int count=0;
            while(i<n && chars[i]==c){
                i++;
                count++;
            }
            chars[write++]=c;
            if(count>1){
                string s=to_string(count);
                for(char c:s){
                    chars[write++]=c;
                }
            }
        }return write;
    }
};