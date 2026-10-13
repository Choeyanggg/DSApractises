class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int write=0;
        int i=0;
        while(i<n){
            char c=chars[i];
            int j=i;
            while(j<n && chars[j]==c){
                j++;
            }
            int freq=j-i;
            chars[write++]=c;
            if(freq>1){
                string s=to_string(freq);
                for(char c:s){
                    chars[write++]=c;
                }
            }
            i=j;
        }return write;
    }
};