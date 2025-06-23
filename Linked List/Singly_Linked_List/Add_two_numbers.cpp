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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Initializing Dummynode for better implemntation of code
        ListNode* dummyHead = new ListNode(-1);
        //initializing curr as dummyhead for traversal
        ListNode* curr = dummyHead;
        ListNode* temp1 = l1;           //represents head1 of first linkedlist
        ListNode* temp2 = l2;           //represents head2 of second linkedlist
        int carry = 0;                  //initializing variable for calculating carry
        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;
            if(temp1)   sum += temp1->val;      //add first number of ll1
            if(temp2)   sum += temp2->val;      //add first number of ll2
            ListNode* newNode = new ListNode(sum%10);               //add the sum to a node of a new linkedlist
            carry = sum/10;         //calculating carry

            curr->next = newNode;       //traversing to the next node
            curr = curr->next;          //moving curr to current node

            if(temp1)   temp1 = temp1->next;            //traversing linkedlist 1 to get the next number
            if(temp2)   temp2 = temp2->next;            //traversing linkedlist2 to get the next number

        }
        if(carry){
            ListNode* newNode = new ListNode(carry);        //at the end if carry id left out adding it to the resultant linked list
            curr->next = newNode;
        }
        return dummyHead->next;     //return head of the resultanat linked list
    }
};