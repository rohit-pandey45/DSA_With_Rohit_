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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i<n; i++){
            fast = fast->next;              //moving fast pointer till n
        }
        if (fast == NULL){
            return head->next;              //Egde Case : if n = length of linkedlist
        }
        while(fast->next != NULL){
            slow = slow->next;              //Traversing till we reach the node just before the node to be deleted
            fast = fast->next;
        }
        
        ListNode* delNode = slow->next;     //storing the node to be deleted in a varaible
        slow->next = slow->next->next;      //changing links
        delete delNode;         //deleting the node
        return head;                //returning head of the linkedlist
    }
};