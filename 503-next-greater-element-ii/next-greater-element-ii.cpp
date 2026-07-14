class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> res;
        for(int i=0;i<n*2;i++){
            while(!st.empty() && nums[st.top()]<nums[i%n]){
                mp[st.top()]=nums[i%n];
                st.pop();
            }
            if(i<n){
                st.push(i);
            }
        }
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        for(int i=0;i<n;i++){
            res.push_back(mp[i]);
        }
        return res;
    }
};