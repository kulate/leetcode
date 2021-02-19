
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = new ListNode(0), *tial = head;
        while (!lists.empty()) {
            ListNode *t = NULL;
            vector<ListNode *>::iterator tit;
            for (auto it = lists.begin(); it != lists.end(); it++) {
                if (*it == NULL)
                    lists.erase(it);
                if (t == NULL || (*it)->val < t->val)
                    t = *it, tit = it;
            }
            tial->next = t, *tit = (*tit)->next, t->next = NULL;
        }
        return head->next;
    }
};

int main(void) {
    Solution solu;
    vector<ListNode *> lists;
    lists.push_back(new ListNode(1));
    solu.mergeKLists(lists);
    return 0;
}