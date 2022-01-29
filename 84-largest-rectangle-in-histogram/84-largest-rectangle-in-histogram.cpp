class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        if(n == 0) return 0;
        if(n == 1) return heights[0];
        
        int maxArea = 0;
        stack<int> s;
        s.push(0);
        
        for(int i = 1; i < n; i++)
        {
            if(s.empty() || heights[s.top()] <= heights[i])
            {
                s.push(i);
            }
            else
            {
                int top = s.top();
                s.pop();
                maxArea = max(maxArea, heights[top] * (s.empty() ? i : i - s.top() - 1));
                i--;
            }
        }
        
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            maxArea = max(maxArea, heights[top] * (s.empty() ? n : n - s.top() - 1));
        }
        
        return maxArea;
    }
};