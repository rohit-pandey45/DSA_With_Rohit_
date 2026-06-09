/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        if(root == nullptr)     return -1;
        int flor = -1;
        while(root){
            if(root->data == k) return k;
            else if(root->data < k){
                flor = root->data;
                root = root->right;
            }
            else{
                // flor = root->data;
                root = root->left;
            }
        }
        return flor;
        
    }
};