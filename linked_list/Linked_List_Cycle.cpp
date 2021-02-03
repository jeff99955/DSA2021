/* Leetcode 141. Linked List Cycle
   https://leetcode.com/problems/linked-list-cycle/
*/

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if (not head or not head->next)
            return false;
        ListNode *slow = head, *fast = head;
        while (slow and fast) {
            slow = slow->next;
            fast = fast->next;
            if (not fast) return false;
            fast = fast->next;
            if (slow == fast) break;
        }
        return (fast) ? true : false;
    }
};
