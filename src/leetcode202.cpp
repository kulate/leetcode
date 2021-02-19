#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        if (n == 1) return true;
        nums.insert(n);
        while (true) {
            n = next(n);
            cout << n << ' ';
            if (n == 1) return true;
            if (nums.find(n) == nums.end()) nums.insert(n);
            else return false;
        }
    }

    int next(int n) {
        int sum = 0;
        while(n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return  sum;
    }
};

int main(void) {
    Solution solu;
    cout << solu.isHappy(7) << endl;
    return 0;
}