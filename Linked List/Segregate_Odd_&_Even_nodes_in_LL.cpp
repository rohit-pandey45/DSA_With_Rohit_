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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;  // Nothing to rearrange
        }
        ListNode* odd = head;               //Initialising odd as index position of first odd index.
        ListNode* even = head->next;;       //Initialising even as index position of first even index.
        ListNode* evenHead = head->next;        //Initialising evenHead as index position of first even index which will be linked to the last odd index and will serve as the first even index in the resultant linked list.
        while(even != NULL && even->next != NULL){          //If length of LL is even , index of the last ele will be even 
            odd->next = odd->next->next;            //If length of LL is odd, then even = null
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
        
    }
};