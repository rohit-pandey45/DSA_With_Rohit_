/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(head == nullptr) return head;
        Node* curr = head, *prev = NULL, *next = curr->next;
        int count = 0;
        while(curr != NULL && count<k){
            next=curr->next;
            curr->next = prev;
            count++;
            prev = curr;
            curr = next;
        }
        if(next!=NULL)  head->next = reverseKGroup(next,k);
        return prev;
    }
};