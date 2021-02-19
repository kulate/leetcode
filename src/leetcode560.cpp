#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    unordered_map<int, int> mp;
    mp[-1] = 1;
    cout << mp[-1] << endl;
    return 0;
}