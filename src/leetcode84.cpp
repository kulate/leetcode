#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        stack<int> stk;
        int ans = 0;
        stk.push(-1);
        for (int i = 0; i < heights.size(); i++) {
            int t = stk.top();
            while (~t && heights[i] < heights[t]) {
                ans = max(ans, (i - t) * heights[t]);
                stk.pop();
                t = stk.top();
            }
            stk.push(i);
        }
        return ans;
    }
};

int main(void) {
    vector<int> heights = {2,1,2};
    Solution solu;
    solu.largestRectangleArea(heights);
    return 0;
}