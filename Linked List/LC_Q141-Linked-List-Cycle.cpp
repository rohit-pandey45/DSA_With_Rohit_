/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != NULL && fast->next != NULL){          //if so, then it is a linear linked list not circular
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){           //eventually slow will be equal to fast bcoz fast is increasing by 2 nodes and slow only by one . So at a particular time the difference between the two will reduce and both will oint to the same node in the circular loop.
                return true;
            }
        }
        return false;
    }
};