class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int n = h.size();
        int mx = 0;
        for(int i=0; i<h.size(); i++){
            while(!st.empty() && h[i] <= h[st.top()]){
                int prevs = -1;
                int t = st.top();
                st.pop();
                if(!st.empty()) prevs = st.top();
                mx = max(mx, h[t]*(i - prevs - 1));
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int prevs = -1, nexts = n;
            int t = st.top();
            st.pop();       
            if(!st.empty()) prevs = st.top();
            mx = max(mx, h[t]*(n - prevs - 1));
        }

        return mx;
    }
};
