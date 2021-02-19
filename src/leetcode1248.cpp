#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> idx;
        idx.push_back(-1);
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] & 1) idx.push_back(i);
        idx.push_back(nums.size());
        int ans = 0;
        for (int i = 1 + k; i < idx.size(); i++) {
            int l = idx[i - k] - idx[i - k - 1], r = idx[i] - idx[i - 1];
            ans += l * r;
        } 
    return ans;
    }
};

int main(void) {
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    Solution solu;
    cout << solu.numberOfSubarrays(nums, k) << endl;
    return 0;
}