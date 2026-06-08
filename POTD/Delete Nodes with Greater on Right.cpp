/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverselist(Node* head){
        Node* prev = nullptr;
        while(head){
            Node* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    Node *compute(Node *head) {
        head = reverselist(head);
        int maxi = head->data;
        Node* curr = head;
        while(curr && curr->next){
            if(curr->next->data < maxi){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
                maxi = max(maxi,curr->data);
            }
        }
        return reverselist(head);
    }
};