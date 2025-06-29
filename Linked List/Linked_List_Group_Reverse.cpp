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
    Node* reverseLinkedList(Node* temp){
        Node* t = temp;
        Node* prev = NULL;
        
        while(t != NULL){
            Node* nextnode = t->next;
            t->next = prev;
            prev = t;
            temp = nextnode;
        }
        return prev;
    }
    Node* getkthnode(Node* temp, int k){
        k -= 1;
        while(temp != NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    Node *reverseKGroup(Node *head, int k) {
        Node* temp = head;
        Node* prevlast = NULL;
        while(temp != NULL){
            Node* kthnode = getkthnode(temp,k);
            if(kthnode == NULL){
                if(prevlast){
                    prevlast->next = temp;
                    break;
                }
                
            }
            Node * nextnode = kthnode->next;
            kthnode->next = NULL;
            reverseLinkedList(temp);
            if(temp == head){
                head = kthnode;
            }
            else{
                prevlast->next = kthnode;
            }
            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
};