class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi=INT_MIN;
        int curr=0;
        while(curr<heights.size()){
            while(!st.empty() && heights[curr]<heights[st.top()]){
                int h=heights[st.top()];
                st.pop();
                int left=st.empty()?-1:st.top();
                int area=h*(curr-left-1);
                maxi=max(maxi,area);
            }
            st.push(curr);
            curr++;
        }
        while(!st.empty()){
            int h=heights[st.top()];
            st.pop();
            int left=st.empty()?-1:st.top();
            curr=heights.size();
            int area=h*(curr-left-1);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};