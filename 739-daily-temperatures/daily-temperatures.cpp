class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            int curr=temperatures[i];
            while(!st.empty() && temperatures[st.top()]<curr){
                res[st.top()]=i-st.top();
                st.pop();
            }st.push(i);
        }
        return res;
    }
};