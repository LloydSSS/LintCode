// http://www.lintcode.com/en/problem/add-two-numbers/#
// 注意是否可以使用l1 l2的节点
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *s = &dummy;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            s->next = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            s = s->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        s->next = l1 == NULL ? l2 : l1;
        if (carry != 0) {
            if (s->next == NULL)
                s->next = new ListNode(carry);
            else
                s->next->val += carry;
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}