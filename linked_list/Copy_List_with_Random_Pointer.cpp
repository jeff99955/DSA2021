/* Leetcode 138. Copy List with Random Pointer
    https://leetcode.com/problems/copy-list-with-random-pointer/
    The original list should not be modified but is not mentioned in the question ==
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    typedef Node node;
    Node* copyRandomList(Node* head) {
        if (not head) return head;
        node *iter = head, *prev, *ret;
        while (iter) {
            node *next = iter->next;
            node *creat = new Node(iter->val);
            iter->next = creat;
            creat->next = next;
            iter = next;
        }
        iter = head;
        while (iter) {
            if (iter->random)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        iter = head, ret = head->next;
        while(iter){
            node *next = iter->next;
            iter->next = next->next;
            if (next->next) next->next = next->next->next;
            iter=iter->next;
        }
        return ret;
    }
};