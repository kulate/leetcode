#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        int fre[128] = {0}, start = 0, dist = t.length(), minLen = s.length() + 1;
        for (auto & ch : t) ++fre[ch];
        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (--fre[s[i]] >= 0) --dist;
            if (!dist) {
                while (!dist) {
                    if (minLen > i - j + 1) {
                        minLen = i - j + 1;
                        start = j;
                    }
                    if (++fre[s[j]] > 0) ++dist;
                    ++j;
                }
            }
        }
        return minLen == s.length() + 1 ? "" : s.substr(start, minLen);
    }
};

int main(void) {
    Solution solu;
    string s = "ADOBECODEBANC", t = "ABC";
    cout << solu.minWindow(s, t) << endl;
    int a = 1;
    long long b = 2;
    cout << max({solu.minWindow(s, t), a, b}) << endl;
}