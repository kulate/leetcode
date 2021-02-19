#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() - 1;
        queue<int> q;
        vector<bool> st(nums.size(), false);
        vector<int> cnt(nums.size(), 0);
        q.push(0);
        st[0] = true;
        while (q.size()) {
            int idx = q.front();
            q.pop();
            if (idx == n) return cnt[n];
            for (int i = idx + 1; i < idx + nums[idx]; i ++) {
                if (i > n) continue;
                if (st[i]) continue;
                cnt[i] = cnt[idx] + 1;
                q.push(i);
                st[i] = true;
            }
        }
        return -1;
    }
};

int main(void) {
    Solution solu;
    vector<int> nums = {2,3,1,1,4};
    cout << solu.jump(nums) << endl;
    return 0;
}