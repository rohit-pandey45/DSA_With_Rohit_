/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(!fast || !fast->next) return;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        while(slow->next != fast){
            slow = slow->next;
        }
        slow->next = nullptr;
    }
};