/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != NULL) {
            // Skip all duplicates
            if (current->next != NULL && current->val == current->next->val) {
                int duplicateVal = current->val;
                while (current != NULL && current->val == duplicateVal) {
                    ListNode* temp = current;
                    current = current->next;
                    delete temp;
                }
                prev->next = current;
            } else {
                prev = current;
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};