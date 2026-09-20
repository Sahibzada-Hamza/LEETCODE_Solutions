class Solution {
public:
    vector<int> left_boundary(const vector<int> heights){
        stack<int> st;
        vector<int> arr(heights.size(),-1);
        for(int i=0;i<=heights.size()-1;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            arr[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return arr;
    }

    vector<int> right_boundary(const vector<int> heights){
        stack<int> st;
        vector<int> arr(heights.size(),-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            arr[i]=(st.empty())?heights.size():st.top();
            st.push(i);
        }
        return arr;
    }

    int largestRectangleArea(vector<int>& heights) {
        long int max_a=0;
        vector<int> l_bds= left_boundary(heights);
        vector<int> r_bds= right_boundary(heights);
        for(int i=0;i<heights.size();i++){
            int width=r_bds[i]-l_bds[i]-1;
            long int area=heights[i]*width;
            max_a=max(max_a,area);
        }
        return max_a;
    }
};