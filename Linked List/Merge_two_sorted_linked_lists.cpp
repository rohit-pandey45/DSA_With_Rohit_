/* Link list Node
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
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* dummyHead = new Node(-1);
        Node* t1 = head1;
        Node* t2 = head2;
        Node* temp = dummyHead;
        while(t1 != NULL && t2 != NULL){
            if(t1->data < t2->data){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if(t1)  temp->next = t1;
        else    temp->next = t2;
        return dummyHead->next;
    }
    
};