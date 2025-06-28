/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    struct Node* reverse(Node* head){
        Node* temp = head;
        Node* prev = NULL;
        Node* nextnode = head;
        while(temp != NULL){
            nextnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextnode;
        }
        return prev;
    }
    struct Node* removeleadingZeros(Node* head){
        // Node* temp = head;
        while(head != NULL && head->next != NULL && head->data == 0){
            head = head->next;
        }
        return head;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = removeleadingZeros(num1);
        num2 = removeleadingZeros(num2);
        
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node* dummyhead = new Node(-1);
        Node* curr = dummyhead;
        Node* temp1 = num1;
        Node* temp2 = num2;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;
            if(temp1)   sum += temp1->data;
            if(temp2)   sum += temp2->data;
            Node* newNode = new Node(sum%10);
            carry = sum/10;
            curr->next = newNode;
            curr = curr->next;
            if(temp1)   temp1 = temp1->next;
            if(temp2)   temp2 = temp2->next;
        }
        if(carry){
            Node* newNode = new Node(carry);
            curr->next = newNode;
        }
        
        return reverse(dummyhead->next);
    }
};