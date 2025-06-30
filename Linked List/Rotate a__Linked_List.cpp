/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* getlastnode(Node* head, int d){
        Node* temp = head;
        int count = 1;
        while(temp != NULL){
            if(count == d){
                return temp;
            }
            count++;
            temp = temp->next;
        }
        return temp;
    }
    Node* rotate(Node* head, int k) {
        if(head == NULL || head->next == NULL ||k == 0){
            return head;
        }
        int len = 1;
        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }
        k = len - k;
        if(k%len == 0)  return head;
        k = k % len;
        tail->next = head;
        Node* lastnode = getlastnode(head,len-k);
        head = lastnode->next;
        lastnode->next = NULL;
        return head;
    }
};