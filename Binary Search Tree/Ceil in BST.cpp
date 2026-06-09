/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        if(root == nullptr) return -1;
        int top = -1;
        while(root){
            if(root->data == x){
                return x;
            }
            else if(root->data > x){
                top = root->data;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return top;
    }
};
